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

vector < int > cat(vector < int >&V1, vector < int >&V2)
{
	vector < int >V(V1.size() + V2.size());
	for (unsigned int i = 0; i < V1.size(); ++i)
		V.at(i) = V1.at(i);
	int cont = 0;
	for (unsigned int j = V1.size(); j < V.size(); ++j, ++cont)
		V.at(j) = V2.at(cont);
	return V;
}

int main()
{
	vector < int >V1(7);
	readVector(V1);
	vector < int >V2(4);
	readVector(V2);
	printVector(cat(V1, V2));
}
