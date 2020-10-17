#include"matrici.h"
#include<iostream>

using namespace std;

bool iszero(double val)
{
	static const long double tolerance = 1e-12;
	if (val < tolerance && val > -tolerance)
		return true;
	return false;
};

Matrix matrix(const std::vector < double >&v, const int nr, const int nc)
{
	Matrix m;
	m.nr = nr;
	m.nc = nc;
	(m.store).resize(nr);
	for (unsigned int r = 0; r < nr; ++r)
		(m.store[r]).resize(nc);
	for (unsigned int r = 0; r < nr; ++r) {
		for (unsigned int c = 0; c < nc; ++c) {
			if (c + r * nc < v.size())
				m.store[r][c] = v[c + r * nc];
			else
				m.store[r][c] = 0;
		}
	}
	return m;
};

void printFullMatrix(const Matrix & m)
{
	for (int r = 0; r < m.nr; ++r) {
		for (int c = 0; c < m.nc; ++c)
			cout << m.store[r][c] << " ";
		cout << endl;
	}
};

SparseMatrix sparse(const Matrix & m)
{
	SparseMatrix sparsa;
	sparsa.store = nullptr;
	for (int r = 0; r < m.nr - 1; ++r) {
		for (int c = 0; c < m.nc - 1; ++c) {
			if (m.store[r][c] != 0) {
				SparseEntry *dainserire = new SparseEntry;
				dainserire->next = nullptr;
				dainserire->r = r;
				dainserire->c = c;
				sparsa.store = dainserire;
			}
		}
	}
	return sparsa;
};

bool is_in_sparse(const SparseMatrix & s, int row, int col)
{
	SparseEntry *aux = new SparseEntry;
	aux->r = row;
	aux->c = col;
	aux = s.store;
	while (aux != nullptr) {
		if ((aux->r == row) && (aux->c == col))
			return true;
		aux = aux->next;
	}
	return false;
}

double getEntry(const SparseMatrix & s, int row, int col)
{
	SparseEntry *aux = new SparseEntry;
	aux->r = row;
	aux->c = col;
	aux = s.store;
	while (aux != nullptr) {
		if ((aux->r == row) && (aux->c == col))
			return aux->val;
		aux = aux->next;
	}
	return 0;
};

Matrix full(const SparseMatrix & s)
{
	Matrix piena;
	piena.nr = s.nr;
	piena.nc = s.nc;
	for (int i = 0; i < piena.nr; ++i) {
		for (int j = 0; j < piena.nc; ++j) {
			if (is_in_sparse(s, i, j))	//da chiedere come fare, se l elemento[i][j] e presente nella SparseMatrix
				piena.store[i][j] = getEntry(s, i, j);	// inserisci val dell elemento[i][j] della matrix
			else
				piena.store[i][j] = 0;
		}
	}
	return piena;
};

SparseMatrix RemoveEntry(const SparseMatrix & s, const int r, const int c)
{
	/*
	   SparseEntry copia; . . . . . 
	   SparseEntry *aux=new SparseEntry; //faccio una copia profonda di s per non sovrascriverla
	   aux=s.store;
	   while(aux!=nullptr)
	   elemento SparseEntry=new SparseEntry;
	   elemento=*aux;
	   elemento.next=
	   sparsecopia.store=elemento; */
	SparseEntry *aux = new SparseEntry;	//versione dove modifico la matrice passata per riferimento
	SparseEntry *prev = new SparseEntry;
	aux = s.store;
	aux->r = s.store->r;
	aux->c = s.store->c;
	while ((aux->r == r && aux->c == c) || aux == nullptr) {
		prev = aux;
		aux = aux->next;
	}
	if (aux->r == r && aux->c == c) {
		prev->next = aux->next;
		aux->next = nullptr;
		delete aux;
	}
	return s;
};

SparseMatrix
setEntry(const SparseMatrix & s, const double val, const int r, const int c)
{
	if (val == 0) {
		RemoveEntry(s, r, c);
		return s;
	}
	SparseEntry *aux = new SparseEntry;	//versione dove modifico la matrice passata per riferimento
	aux = s.store;
	while ((aux->r != r && aux->c != c) || aux != nullptr) {	//se esiste gia l elemento lo aggiorno
		aux = aux->next;
	}
	if (aux->r == r && aux->c == c) {
		aux->val = val;
		return s;
	}
	if (aux == nullptr) {	//se non esiste, aggiungo cella
		aux = s.store;
		SparseEntry *prev = new SparseEntry;
		while (aux->r < r && aux->c < c) {
			prev = aux;
			aux = aux->next;
		}
		SparseEntry *daaggiungere = new SparseEntry;
		daaggiungere->r = r;
		daaggiungere->c = c;
		daaggiungere->val = val;
		daaggiungere->next = aux->next;
		prev->next = daaggiungere;
	}
	return s;
};

void printSparseMatrix(const SparseMatrix & s)
{
	for (int r = 0; r < s.nr; ++r) {
		for (int c = 0; c < s.nc; ++c)
			cout << getEntry(s, r, c) << " ";
		cout << endl;
	}
};

SparseMatrix add(const SparseMatrix & s1, const SparseMatrix & s2)
{
	if ((s1.nr != s2.nr) || (s1.nr != s2.nr)) {
		string err = "Sparse Matrix sizes mismatch";
		throw err;
	}
	SparseMatrix sum;
	double somma = 0;
	for (int r = 0; r < s1.nr; ++r) {
		for (int c = 0; c < s1.nc; ++c) {
			somma = getEntry(s1, r, c) + getEntry(s2, r, c);
			setEntry(sum, somma, r, c);
		}
	}
	sum.nr = s1.nr;
	sum.nc = s1.nc;
	return sum;
};

SparseMatrix mult(const SparseMatrix & s1, const SparseMatrix & s2)
{
	if ((s1.nr != s2.nr) || (s1.nr != s2.nr)) {
		string err = "Sparse Matrix sizes mismatch";
		throw err;
	}
	SparseMatrix multi;
	double moltiplicazione = 0;
	for (int r = 0; r < s1.nr; ++r) {
		for (int c = 0; c < s1.nc; ++c) {
			moltiplicazione =
			    getEntry(s1, r, c) * getEntry(s2, r, c);
			setEntry(multi, moltiplicazione, r, c);
		}
	}
	multi.nr = s1.nr;
	multi.nc = s1.nc;
	return multi;
};
