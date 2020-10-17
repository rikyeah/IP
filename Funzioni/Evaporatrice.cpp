#include<iostream>

using namespace std;

int giornirimanenti(float litri, int perc, float soglia)
{
	float sottratto = (litri * perc) / 100;
	int giorni = 0;
	while (litri > soglia) {
		litri = litri - sottratto;
		++giorni;
	}
	return giorni;
}

int main()
{
	int perc;
	float litri, soglia;
	cout << "Dimmi litri, perc e soglia" << endl;
	cin >> litri >> perc >> soglia;
	cout << "Puoi utilizzare l' evaporatrice per ancora " <<
	    giornirimanenti(litri, perc, soglia) << " giorni" << endl;

	return 0;
}
