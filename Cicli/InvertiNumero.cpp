#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	cout << "Dimmi numero da invertire" << endl;
	int k;
	cin >> k;
	cout << "Invertendo " << k << " si ottiene ";
	if (k <= 0) {
		cout << "-";
		k = -k;
	}
	int inv = 0;
	while (k > 0) {
		int mod = (k % 10);
		k = k / 10;
		inv = inv * 10;
		inv = inv + mod;
	}
	cout << inv << endl;
	return 0;
}
