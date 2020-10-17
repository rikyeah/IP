#include<iostream>
#include<vector>

using namespace std;

vector < int > insert(vector < int >&V, int i, int val)
{
	if (i > V.size()) {
		int exc = -1;
		throw exc;
	}
	if (i == V.size()) {
		vector < int >V2(V);
		V2.push_back(val);
		return V2;
	}

	vector < int >V2(V);
	for (unsigned int y = V2.size(); y < i; --y)
		V2.push_back(V2.at(y));
	V2.at(i) = val;

	return V2;
}

void printVector(vector < int >&V)
{
	for (unsigned int i = 0; i < V.size(); ++i)
		cout << V.at(i) << endl;
}

int main()
{
	vector < int >Vec(5, 5);
	try {
		Vec = insert(Vec, 2, 4);
		printVector(Vec);
		//printVector(insert(Vec,4,4));
	}
	catch(int exc) {
		cout << exc << endl;
	};

}
