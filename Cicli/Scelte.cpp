#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout << "1 Prima scelta" << endl;
	cout << "2 Seconda scelta" << endl;
	cout << "3 Terza scelta" << endl;
	cout << "0 uscita dal programma" << endl;
	cout << "fai una scelta" << endl;
	int answer;
	cin >> answer;
	while (answer != 0) {
		if (answer == 1)
			cout << "hai fatto la prima scelta" << endl;
		else if (answer == 2)
			cout << "hai fatto la seconda scelta" << endl;
		else if (answer == 3)
			cout << "hai fatto la terza scelta" << endl;
		else
			cout << "scelta non valida" << endl;
		cout << "fai una nuova scelta" << endl;
		cin >> answer;
	}
	cout << "hai scelto di uscire dal programma" << endl;
}
