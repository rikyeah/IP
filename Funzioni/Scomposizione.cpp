#include<iostream>

using namespace std;

void scomposizione(int num)
{
	int fattore = 2;
	while (num > 1) {
		int volte = 0;
		while ((num % fattore) == 0) {
			++volte;
			num = num / fattore;
		}
		if (volte != 0) {
			cout << fattore << "^" << volte;
			if (num == 1)
				cout << endl;
			if (num != 1)
				cout << "*" << endl;
		}
		++fattore;
	}
}

int main()
{
	cout << "Dimmi il numero da scomporre" << endl;
	int numero;
	cin >> numero;
	cout << endl;
	scomposizione(numero);

	return 0;
}
