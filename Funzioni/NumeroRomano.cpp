// scrivere numero romano dato numero in decimale dato in input

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	cout << "Dimmi numero con cifre arabe da 1 a 3000" << endl;
	int arabo;
	cin >> arabo;
	int prima, seconda, terza, quarta;
	quarta = arabo % 10;
	terza = (arabo % 100 - quarta) / 10;
	seconda = (arabo % 1000 - quarta - terza) / 100;
	prima = (arabo % 10000 - quarta - terza - seconda) / 1000;
	if (prima == 1)
		cout << "M";
	if (prima == 2)
		cout << "MM";
	if (prima == 3)
		cout << "MMM";
	switch (seconda) {
	case 1:
		cout << "C";
		break;
	case 2:
		cout << "CC";
		break;
	case 3:
		cout << "CCC";
		break;
	case 4:
		cout << "CD";
		break;
	case 5:
		cout << "D";
		break;
	case 6:
		cout << "DC";
		break;
	case 7:
		cout << "DCC";
		break;
	case 8:
		cout << "DCCC";
		break;
	case 9:
		cout << "CM";
		break;
	default:
		cout << "";
	}
	switch (terza) {
	case 1:
		cout << "X";
		break;
	case 2:
		cout << "XX";
		break;
	case 3:
		cout << "XXX";
		break;
	case 4:
		cout << "XL";
		break;
	case 5:
		cout << "L";
		break;
	case 6:
		cout << "LX";
		break;
	case 7:
		cout << "LXX";
		break;
	case 8:
		cout << "LXXX";
		break;
	case 9:
		cout << "XC";
		break;
	default:
		cout << "";
	}
	switch (quarta) {
	case 1:
		cout << "I";
		break;
	case 2:
		cout << "II";
		break;
	case 3:
		cout << "III";
		break;
	case 4:
		cout << "IV";
		break;
	case 5:
		cout << "V";
		break;
	case 6:
		cout << "VI";
		break;
	case 7:
		cout << "VII";
		break;
	case 8:
		cout << "VIII";
		break;
	case 9:
		cout << "IX";
		break;
	default:
		cout << "";
	}
	cout << endl;
	return 0;
}
