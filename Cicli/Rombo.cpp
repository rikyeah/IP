#include<string>
#include<iostream>

using namespace std;

int main()
{
	cout << "dimmi il numero" << endl;
	int n, diag;
	cin >> n;
	diag = (n * 2) + 1;
	int cont = 0;
	for (int i = 0; i < diag; ++ ++i)	// eseguiamo le cose diag/2 volte
	{
		for (int j = ((diag + 1) / 2) + cont - 1; j > 0; --j)
			cout << " ";
		for (int j = ((diag + 1) / 2) - n; j > 0; --j)
			cout << "*";
		cout << endl;
		cont = cont - 1;
		n = n - 2;
	}
	cont = 1;
	n = (diag - 1) / 2;
	for (int i = 1; i < diag; ++ ++i) {
		for (int j = cont; j > 0; --j)
			cout << " ";
		for (int j = 2 * n - 1; j > 0; --j)
			cout << "*";
		n = n - 1;
		cont = cont + 1;
		cout << endl;
	}
	return 0;
}
