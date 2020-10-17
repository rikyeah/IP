#include<iostream>

using namespace std;

int func(int n, int d)
{
	int numero = n;
	int cifra1, cifra2;
	do {
		cifra1 = numero % 10;
		numero = numero / 10;

		--numero;
	}
	while ((cifra1 != d) && (cifra2 != d));
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
