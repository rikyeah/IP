#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	cout << "dimmi il numero intero" << endl;
	long int numero, n1, n2;
	cin >> numero;
	n2 = 0;
	n1 = numero;
	while (n1 > 0) {
		n2 = (n2 * 10) + (n1 % 10);
		n1 = n1 / 10;
	}
	if (numero == n2)
		cout << "numero palindromo" << endl;
	else
		cout << "numero non palindromo" << endl;
	return 0;
}
