#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	cout << "Dimmi numero positivo" << endl;
	int k;
	cin >> k;
	if (k < 0)
		cout << "ho detto positivo" << endl;
	else {
		int cont = 0;
		do {
			k = k / 10;
			++cont;
		}
		while (k != 0);
		cout << cont << " cifre" << endl;
	}
	return 0;

}
