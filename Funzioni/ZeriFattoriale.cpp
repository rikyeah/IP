#include<iostream>

using namespace std;

int calcolazeri(int n)
{
	if ((n == 0) || (n == 1))
		return 0;
	int num1 = n;
	int multiplo1 = 0, multiplo2 = 0;
	while ((num1 / 5) > 0) {
		// cout<<"divisione"<<num1/5<<endl;
		++multiplo1;
		// cout<<"multiplo1 "<<multiplo1<<endl;
		num1 = num1 - 5;
	}
	cout << multiplo1 << endl;
	int num2 = n;
	int cont = 0;
	while ((num2 / 50) > 0) {
		num2 = num2 - 50;
		++cont;
		++cont;
	}
	cout << cont << endl;
	int risultato = multiplo1 + multiplo2 + cont;

	return risultato;
}

int main()
{
	cout << "Dimmi il numero" << endl;
	int n;
	cin >> n;
	cout << calcolazeri(n) << endl;

	return 0;
}
