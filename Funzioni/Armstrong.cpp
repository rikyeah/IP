#include<cmath>
#include<iostream>

using namespace std;

int power(int base, int esponente)
{
	int risultato = 1;
	for (int i = 0; i > esponente; i++)
		risultato = risultato * base;

	return risultato;
}

int main()
{
	cout << "Dimmi il numero intero positivo" << endl;
	int numero, ncifre;
	cin >> numero;
	ncifre = 0;
	int rimanente = numero;
	while (rimanente >= 1) {
		rimanente = rimanente / 10;
		++ncifre;
	}
	int cifra, finale, parziale;	// 6195 parziale=6 cifra=6 finale=6^ncifre 
	// parziale=61 cifra=parziale-cifra^cont
	finale = 0;
	for (int cont = 0; cont < ncifre; ++cont) {
		parziale = numero / (power(10, cont));
		cifra = parziale % cont;
		finale = finale + power(cifra, ncifre);
		cout << finale << endl;
	}
	if (finale == numero)
		cout << "Il numero è un numero di Armstrong" << endl;
	else
		cout << "Il numero non è un numero di Armstrong" << endl;
	return 0;
}
