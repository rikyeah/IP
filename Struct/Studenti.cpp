#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct studente {
	unsigned int matricola;
	string nome;
	string cognome;
	unsigned int anno;
	unsigned int mese;
	unsigned int giorno;
	int data = anno * 10000 + mese * 100 + giorno;
	double voto;
};

int main()
{
	studente s1;
	studente s2;
	studente s3;
	cout <<
	    "Dimmi dati dello studente: n matrcola, nome, cognome, anno di nascita, mese, giorno, voto medio"
	    << endl;
	cin >> s1.matricola >> s1.nome >> s1.cognome >> s1.anno >> s1.
	    mese >> s1.giorno >> s1.voto;
	cout <<
	    "Dimmi dati dello studente: n matrcola, nome, cognome, anno di nascita, mese, giorno, voto medio"
	    << endl;
	cin >> s2.matricola >> s2.nome >> s2.cognome >> s2.anno >> s2.
	    mese >> s2.giorno >> s2.voto;
	cout <<
	    "Dimmi dati dello studente: n matrcola, nome, cognome, anno di nascita, mese, giorno, voto medio"
	    << endl;
	cin >> s3.matricola >> s3.nome >> s3.cognome >> s3.anno >> s3.
	    mese >> s3.giorno >> s3.voto;

	return 0;
}
