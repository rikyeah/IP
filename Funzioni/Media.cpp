#include<iostream>

using namespace std;

int media()
{
	string risposta = "si";
	int cont = 0;
	int num = 0;
	int somma = 0;
	while (risposta != "no") {
		if (cont != 0) {
			cout << "vuoi continuare? rispondi no per finire" <<
			    endl;
			cin >> risposta;
		}
		if (risposta != "no") {
			cout << "dimmi un numero" << endl;
			cin >> num;
			somma = somma + num;
			cont++;
		}
	}
	return somma / cont;
}

int main()
{
	cout << "programma che esegue una media" << endl;
	int risultato = media();
	cout << "la media è " << risultato << endl;

	return 0;
}
