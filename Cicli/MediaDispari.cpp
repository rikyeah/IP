#include<iostream>

using namespace std;

int main()
{
	int a, somma, cont;
	const int MAX = 10;
	cont = 0;
	somma = 0;
	while (cont < MAX) {
		cout << "dimmi un numero dispari" << endl;
		cin >> a;
		if ((a % 2) != 0) {
			somma = somma + a;
			++cont;
		}
	}
	cout << "la media e' " << (somma / MAX) << endl;
	return 0;
}
