#include<iostream>

using namespace std;

int main()
{
	int n, avg, cont;
	const int SENTINELLA = -1;
	cont = 0;
	avg = 0;
	do {
		cout << "dimmi la tua età" << endl;
		cin >> n;
		if ((n >= 0) && (n < 117)) {
			avg = avg + n;
			++cont;
		} else
			cout << "non dire bugie" << endl;
	}
	while (n != SENTINELLA);
	cout << "la media è " << (avg / cont) << endl;
	return 0;
}
