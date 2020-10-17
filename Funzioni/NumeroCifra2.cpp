#include<iostream>

using namespace std;

bool controllocifra(int numero, int cifra)
{
	int estratta;
	do {
		estratta = numero % 10;
		numero = numero / 10;
		if (estratta == cifra)
			return true;
		cout << numero << endl;
	}
	while (numero > 0);
	return false;
}

int func(int n, int d)
{
	int numero = n;
	int cifra;
	bool controllo;
	do {
		controllo = controllocifra(numero, cifra);
		--numero;
		cout << "Ciao" << endl;
	}
	while (!controllo);
	++numero;
	return numero;
}

int main()
{
	int n, d;
	cout << "Dimmi il numero" << endl;
	cin >> n;
	cout << "Dimmi la cifra" << endl;
	cin >> d;
	cout << func(n, d) << endl;

	return 0;
}
