#include<iostream>

using namespace std;

long int fattoriale(int num)
{
	if (num < 0) {
		int err = -1;
		throw err;
	}
	if (num == 0) {
		return 1;
	}
	long int fact = num;
	for (int i = num - 1; i > 1; --i) {
		fact = fact * (i);
	}
	return fact;
}

int main()
{
	try {
		cout << "Dimmi il numero positivo" << endl;
		int numero;
		cin >> numero;
		long int risultato = fattoriale(numero);
		cout << "Il suo fattoriale è " << risultato << endl;
	}
	catch(int err) {
		cout << "Non hai dato un numero positivo" << endl;
	}
	return 0;
}
