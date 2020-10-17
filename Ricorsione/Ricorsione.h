#ifndef RICORSIONE
#define RICORSIONE

typedef int type;

struct cell {
	type info;
	cell *next;
};

typedef cell *list;

int fact(const int &);

int coeffbin(const int &, const int &);

int fibonacci(const int &);

int MCD(const int &, const int &);

bool is_in(const list &, type);

int length(const list & l);

bool rec_insertElemInOrder(list &, type);

bool rec_removeElemInOrder(list & l, type x);

void reverseList1(list & l);

list reverseList2(const list & l);

#endif
