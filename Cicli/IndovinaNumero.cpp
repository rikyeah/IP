#include<iostream>

using namespace std;

int main()
{
	const int MAXT = 10;
	int numero = 40;
	int guess = -1;
	int cont = 0;
	do {
		cout << "fai una prova tra 1 e 100" << endl << endl;
		cin >> guess;
		if (guess == numero)
			cout << "Bravo" << endl << endl;
		else {
			cout << "riprova" << endl << endl;
			if (guess > numero)
				cout <<
				    "Il numero che stai cercando è piu piccolo"
				    << endl;
			else
				cout <<
				    "il numero che stai cercando è piu grande"
				    << endl;
		}
		++cont;
	}
	while ((guess != numero) && (cont < MAXT));
	if (guess != numero)
		cout << "non ci sei riuscito" << endl;
	return 0;
}
