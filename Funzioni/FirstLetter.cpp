#include<iostream>

using namespace std;

char FirstLetter()
{
	cout << "Inserisci una lettera maiuscola" << endl;
	char first;
	while ((first > 90) || (first < 65)) {
		cin >> first;
	}
	char c = 'Z';
	while ((first < 'Z') && (first > 'A')) {
		if (c < first)
			first = c;
		cout <<
		    "Inserisci una lettera maiuscola (o altro carattere per terminare)"
		    << endl;
		cin >> c;
	}
	return first;
}

int main()
{
	char risultato = FirstLetter();
	cout << risultato << endl;
}
