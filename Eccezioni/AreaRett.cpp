#include<iostream>
#include<cmath>

using namespace std;

float area(float height, float base)
{
	if ((height <= 0) || (base <= 0)) {
		int exc = -1;
		throw exc;
	}
	return height * base;
}

int main()
{
	cout << "Dimmi base e altezza positivi" << endl;
	float base, altezza;
	cin >> base >> altezza;
	try {
		float result = area(altezza, base);
		cout << result << endl;
	}
	catch(int exc) {
		cout << "valori non validi" << endl;
	}
}
