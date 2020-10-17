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

void SelectionSort_vector(vector < int >&V)
{
	int temp = 0;
	int pos_min;
	for (unsigned int i = 0; i < V.size() - 1; ++i) {
		pos_min = i;
		for (unsigned int j = i; j < V.size(); ++j) {
			if (V.at(j) < V.at(pos_min))
				pos_min = j;
		}
		if (pos_min != i) {	//swap
			temp = V.at(i);
			V.at(i) = V.at(pos_min);
			V.at(pos_min) = temp;
		}
	}
}

int main()
{
	vector < int >VEC(5);
	readVector(VEC);
	SelectionSort_vector(VEC);
	printVector(VEC);
}
