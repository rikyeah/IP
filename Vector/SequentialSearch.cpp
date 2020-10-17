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

int SequentialSearch_vector(const vector < int >&V, int item)
{
	for (unsigned int i = 0; i < V.size(); ++i) {
		if (V.at(i) == item)
			return i;
	}
	return -1;
}

int main()
{
	vector < int >VEC(5);
	readVector(VEC);
	int item;
	cout << "dimmi l' elemento da cercare" << endl;
	cin >> item;
	cout << SequentialSearch_vector(VEC, item);
	//printVector(VEC);
}
