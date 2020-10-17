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

vector < int > reverse(vector < int >&V)
{
	vector < int >V_rev(V.size());
	for (unsigned int i = 0; i < V.size(); ++i) {
		cout << "i=" << i << " e V.at(5-i)=" << V.at(V.size() - 1 -
							     i) <<
		    " da mettere in v_rev(i)=" << V_rev.at(i) << endl;
		V_rev.at(i) = V.at(V.size() - 1 - i);
	}
	return V_rev;
}

int main()
{
	vector < int >VEC(5);
	readVector(VEC);
	vector < int >VEC2 = reverse(VEC);
	printVector(VEC2);
}
