#include<iostream>

using namespace std;

int risultato(int a, int b, int max)
{
	int somma = 0;
	int contatore = 1;
	while (contatore <= max) {
		cout << "somma " << somma << "contatore " << contatore << endl;
		if ((contatore % a == 0) || (contatore % b == 0))
			somma = somma + contatore;
		contatore++;
	}
	return somma;
}

int main()
{
	cout << "dimmi i due numeri divisori a e b e il max fino a cui contare"
	    << endl;
	int a, b, max;
	cin >> a >> b >> max;
	cout << "il risultato è " << risultato(a, b, max) << endl;

	return 0;
}
