#include"Ricorsione.h"
#include<string>
#include<iostream>

using namespace std;

int fact(const int &n)
{
	if (n < 0) {
		std::string exc =
		    "cannot accept negative number in factiorial function";
		throw exc;
	};
	if (n == 0)
		return 1;
	return n * fact(n - 1);
};

int coeffbin(const int &n, const int &k)
{
	if (n < 0 || k < 0) {
		std::string exc =
		    "cannot accept navative numbers in coeffbin function";
		throw exc;
	}
	if (n == k || k == 0)
		return 1;
	return (coeffbin(n - 1, k - 1) + coeffbin(n - 1, k));
};

int fibonacci(const int &n)
{
	if (n == 0 || n == 1)
		return 1;
	return (fibonacci(n - 1) + fibonacci(n - 2));
};

int MCD(const int &m, const int &n)
{
	if (m == n)
		return m;
	if (m > n)
		return MCD(m - n, n);
	return MCD(m, n - m);
};

bool is_in(const list & l, type x)
{
	if (l == nullptr)
		return 0;
	if (l->info == x)
		return 1;
	return is_in(l->next, x);
};

int length(const list & l)
{
	if (l == nullptr)
		return 0;
	return 1 + length(l->next);
};

bool rec_insertElemInOrder(list & l, type x)
{
	cell *toinsert = new cell;
	toinsert->info = x;
	toinsert->next = nullptr;
	if (l == nullptr) {
		//cerr<<"inserimento in coda o vuota"<<endl;
		l = toinsert;
		//cerr<<"inserito in coda o vuota"<<endl;
		return 1;
	}
	if (l->info == x)
		return 0;
	if (l->info > x) {
		//cerr<<"inserimento in 2 posizione"<<endl;
		toinsert->next = l;
		l = toinsert;
		return 1;
	}
	return rec_insertElemInOrder(l->next, x);
	return 0;
};

bool rec_removeElemInOrder(list & l, type x)
{
	if (l == nullptr)	//se la lista è vuota o arrivo alla fine
		return 0;
	if (l->next == nullptr) {	//se sono all ultimo elemento, non esiste un prossimo elemento
		if (l->info == x) {	//se quest ultimo elemento e quello che cerco
			delete l;
			l = nullptr;
			return 1;
		}
		return 1;	//se non lo è
	}
	if (l->info == x) {	//se il primo delemento e quello che cerco
		cell *aux;
		aux = l->next;
		l->next = nullptr;
		delete l;
		l = aux;
		return 1;
	}
	if (l->next->info == x) {	//se il prossimo elemento è quello che cerco
		cell *aux;
		aux = l->next;
		l->next = aux->next;
		aux->next = nullptr;
		delete aux;
		return 1;
	}
	return rec_removeElemInOrder(l->next, x);
};

//fare insert in fondo
void insertInHead(list & l1, type x)
{
	cell *aux = new cell;
	aux->next = l1;
	aux->info = x;
	l1 = aux;
};

void reverseList1(list & l)
{
	list l1 = nullptr;
	if (l == nullptr || l->next == nullptr)
		return;
	l1 = l->next;
	reverseList1(l1);
	l->next->next = l;
	l->next = nullptr;
	l = l1;
};

list reverseList2aux(list & dest, const list & source)
{
	cout << "sono dentro la funz" << endl;
	if (source != nullptr) {
		cout << "inserisco il valore " << source->info << " nella lista"
		    << endl;
		insertInHead(dest, source->info);
		reverseList2aux(dest, source->next);
	}
	return dest;
};

list reverseList2(const list & source)
{
	list dest = nullptr;
	return reverseList2aux(dest, source);;	//CONTINUARE DA QUIIIIIIIIIIIIIIIIIIIIIIIIII(forse e gia giusto)
};
