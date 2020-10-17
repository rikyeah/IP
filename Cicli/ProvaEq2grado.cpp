#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double a, b, c, x1, x2, delta;
	cout << "inserisci coefficente a" << endl;
	cin >> a;
	cout << "inserisci coefficente b" << endl;
	cin >> b;
	cout << "inserisci termine noto" << endl;
	cin >> c;
	delta = ((b * b) - (4 * a * c));
	x1 = (-(b) - (sqrt(delta))) / (2 * a);
	x2 = (-(b) + (sqrt(delta))) / (2 * a);
	if (delta == 0)
		cout << "soluzioni incidenti x1:" << x1 << "x2: " << x2 << endl;
	if (delta < 0)
		cout << "non ci sono soluzioni reali" << endl;
	else
		cout << "le soluzioni sono x1: " << x1 << " x2: " << x2 << endl;

	return 0;
}
