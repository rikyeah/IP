#include"Ricorsione.h"
#include<iostream>
#include<ctime>

using namespace std;

void print(const list & l)
{
	cell *aux = l;
	while (aux != nullptr) {
		cout << aux->info << " ";
		aux = aux->next;
	}
	cout << endl;
};

int main()
{
	srand(time(0));
	list lista1 = nullptr;
	for (int i = 0; i < 10; ++i)
		rec_insertElemInOrder(lista1, rand() % 7);
	cout << "Lista: ";
	print(lista1);
	cout << "Capovolgo la lista" << endl;
	list inverso = nullptr;
	inverso = reverseList2(lista1);
	cout << "ecco la lista capovolta" << endl;
	print(inverso);
}
