#include<cmath>
#include<iostream>

using namespace std;

int reverse(int k)
{
	int risultato = 0;
	int cifra = 0;
	for (int molti = 1; k > 0; molti * 10) {
		cifra = k % 10;
		cout << cifra << endl;
		k = k / 10;
		cout << k << endl;
		risultato = (risultato * 10) + cifra;
		cout << risultato << endl;
	}
	return risultato;
}

int main()
{
	cout << "Dimmi il numero da invertire" << endl;
	int numero;
	cin >> numero;
	int fine = reverse(numero);
	cout << fine << endl;
}
