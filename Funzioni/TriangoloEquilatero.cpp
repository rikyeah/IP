#include<iostream>

using namespace std;

void riga(int spazi, int asterischi)
{
	for (int i = spazi - 1; i > 0; --i)
		cout << " ";
	for (int j = asterischi; j > 0; --j)
		cout << "* ";
}

int main()
{
	cout << "Dimmi l'altezza del triangolo da costruire" << endl;
	int h;
	cin >> h;
	int asterischi = 1;
	int spazi = h;
	while (h > 0) {
		riga(spazi, asterischi);
		++asterischi;
		--spazi;
		--h;
		cout << endl;
	}
	return 0;
}
