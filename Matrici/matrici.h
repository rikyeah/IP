#include<vector>

struct Matrix {
	std::vector < std::vector < double >>store;
	int nr;
	int nc;
};

struct SparseEntry {		//entrata di matrice sparsa
	int r;
	int c;
	double val;
	SparseEntry *next;
};

struct SparseMatrix {
	SparseEntry *store;
	int nr;
	int nc;
	int nnz;		//elemento non nullo
};

bool iszero(double val);

Matrix matrix(const std::vector < double >&v, const int nr, const int nc);

void printFullMatrix(const Matrix & m);

SparseMatrix sparse(const Matrix & m);

Matrix full(const SparseMatrix & s);

SparseMatrix RemoveEntry(const SparseMatrix & s, const int r, const int c);

SparseMatrix setEntry(const SparseMatrix & s, const double val, const int r,
		      const int c);

double getEntry(const SparseMatrix & s, int row, int col);

void printSparseMatrix(const SparseMatrix & s);

SparseMatrix add(const SparseMatrix & s1, const SparseMatrix & s2);
