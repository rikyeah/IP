#include<iostream>
#include<vector>

using namespace std;

vector < int > Crivello(int N)
{
	//imposto tutto l'array a true
	vector < int >isprime(N);
	for (int i = 2; i < isprime.size(); ++i)
		isprime.at(i) = true;
	//partendo da p=2 e fino a N/p imposto false tutti i multipli di p tramite un ciclo
	for (int i = 2; i < N; ++i) {
		if (isprime.at(i) == true) {
			for (int j = i; j * i < N; ++j)
				isprime.at(i * j) = false;
		}
	}
	//procedura ripetuta finche l' elemento corrispondente è true, ossia primo

	for (int i = 2; i < N; ++i) {
		if (isprime.at(i) == true)
			cout << i << " numero primo" << endl;
	}

	return isprime;
};

int main()
{
	int n = 1000;
	Crivello(n);
}
