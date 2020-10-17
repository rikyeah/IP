#include<iostream>
#include<string>

using namespace std;

struct OutOfRangeError {
	string paramName;
	int paramValue;
};

void replicate(int length, char c)
{
	if (length < 0) {
		OutOfRangeError err;
		err.paramName = "length";
		err.paramValue = length;
		throw err;
	}
	for (int i = 1; i <= length; ++i)
		cout << c;
}

int main()
{
	try {
		cout << "insersci un numero maggiore di 0" << endl;
		int length;
		cin >> length;
		cout << "Dimmi il carattere" << endl;
		char c;
		cin >> c;
		replicate(length, c);
	}
	catch(OutOfRangeError err) {
		cout << "Hai inserito " << err.
		    paramValue << " che non è valido" << endl;
	}
}
