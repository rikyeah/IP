#include<iostream>
#include<vector>

using namespace std;

void readVector(vector < int >&V)
{
	for (unsigned int i = 0; i < V.size(); ++i)
		cin >> V.at(i);
}

void printVector(const vector < int >&V)
{
	for (unsigned int i = 0; i < V.size(); ++i)
		cout << V.at(i) << endl;
}

int main()
{
	vector < int >VEC(5);
	readVector(VEC);
	printVector(VEC);
}
