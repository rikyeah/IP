#include<iostream>

using namespace std;

int
annodopo(unsigned int popolazione, unsigned int percnati,
	 unsigned int arrivati, int cont)
{
	float nati = (popolazione * percnati) / 100;
	popolazione = popolazione + nati + arrivati;
	cout << popolazione;
	return popolazione;
}

int
annidopo(unsigned int num, unsigned int popolazione, unsigned int percnati,
	 unsigned int arrivati)
{
	int cont = 0;
	while (num != 0) {
		popolazione = annodopo(popolazione, percnati, arrivati, cont);
		num--;
		cont++;
	}
	return popolazione;
}

int main()
{
	unsigned int popolazione;
	unsigned int percnati;
	unsigned int arrivati;
	int n;
	cout <<
	    "Dimmi popolazione, percentuale dei nati e il numero degli arrivati e il numero degli anni"
	    << endl;
	cin >> popolazione >> percnati >> arrivati >> n;
	popolazione = annidopo(n, popolazione, percnati, arrivati);
	cout << "la popolazione l' anno successivo sara di " << popolazione <<
	    endl;

	return 0;
}
