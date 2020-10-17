#include<string>
#include<iostream>

using namespace std;

int main()
{
	cout << "dimmi il numero" << endl;
	int n;
	cin >> n;
	n = (n * 2) + 1;
	int asterischi = 1;
	int spazi = (n / 2);
	for (int i = 0; i <= (n / 2); ++i, asterischi = asterischi + 2, --spazi) {
		for (int j = spazi; j > 0; --j)
			cout << " ";
		for (int j = asterischi; j > 0; --j)
			cout << "*";
		cout << endl;
	}
	asterischi = asterischi - 4;
	spazi = 1;
	for (int i = 0; i < (n / 2); ++i, asterischi = asterischi - 2, ++spazi) {
		for (int j = spazi; j > 0; --j)
			cout << " ";
		for (int j = asterischi; j > 0; --j)
			cout << "*";
		cout << endl;
	}
	return 0;
}
