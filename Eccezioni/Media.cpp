#include<iostream>
#include<cmath>

using namespace std;

double average(int hm)
{
	if (hm <= 0) {
		string exc = "numero non positivo";
		throw exc;
	} else {
		double part = 0;
		double numero = 0;
		for (int i = 0; hm > i; ++i) {
			cout << "dimmi il numero" << endl;
			cin >> numero;
			part = part + numero;
		}
		return part / hm;
	}
}

int main()
{
	try {
		cout << "Di quanti numeri vuoi fare la media?" << endl;
		int volte;
		cin >> volte;
		double risultato = average(volte);
		cout << "la media è " << risultato << endl;
	}
	catch(string exc) {
		cout << exc << endl;
	}
}
