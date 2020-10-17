#include<iostream>

using namespace std;

void disegna(int min, int mag)
{
	for (int j = mag - min + 1; j > 0; --j) {
		for (int i = mag - (j - 1); i > 0; --i)
			cout << "x";
		cout << endl;
	}
}

int main()
{
	int min, mag;
	cout << "dimmi base minore e base maggiore" << endl;
	cin >> min >> mag;
	disegna(min, mag);

	return 0;
}
