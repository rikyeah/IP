#include<iostream>

using namespace std;

void triangle(int length)
{
	if (length < 0) {
		int err = -1;
		throw err;
	}
	for (int j = 1; j <= length; ++j) {
		for (int i = j; i > 0; --i)
			cout << "*";
		cout << endl;
	}
}

int main()
{
	try {
		cout << "Dimmi il numero di volte" << endl;
		int lunghezza;
		cin >> lunghezza;
		triangle(lunghezza);
	}
	catch(int err) {
		cout << "Valore non valido" << endl;
	}
	return 0;
}
