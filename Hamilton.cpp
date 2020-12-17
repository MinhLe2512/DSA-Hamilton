#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void readInput(string input_file, int& n, vector<vector<int>>& m) {
	ifstream fin(input_file);
	//read the numbers of cities
	fin >> n;

	//create NxN matrix
	for (int i = 0; i < n; i++) {
		vector<int> row;

		for (int j = 0; j < n; j++) row.push_back(0);
		m.push_back(row);
	}

	//read paths
	int a, b, c;
	while (!fin.eof()) {
		fin >> a;
		if (a == -1) break;
		else {
			fin >> b;
			fin >> c;
			m[a - 1][b - 1] = c;
			m[b - 1][a - 1] = c;
		}
	}

	fin.close();
}

void matrixToList(vector<vector<int>> m, vector<vector<int>>& l) {//Convert from matrix to list
	for (vector<vector<int>>::iterator i = m.begin(); i != m.end(); i++) {
		vector<int> row;
		bool check = false;

		//push adjacency elements
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
			if ((*j) != 0) {
				row.push_back(j - (*i).begin());
				check = true;
			}
		//check isolated vertices
		if (check == false) row.push_back(0);
		l.push_back(row);
	}
}
void printMatrix(vector<vector<int>> m) {//Print matrix to test
	for (vector<vector<int>>::iterator i = m.begin(); i != m.end(); i++) {
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) cout << (*j) << " ";
		cout << endl;
	}
}

int main()
{
	int n;
	vector<vector<int>> m, l;
	readInput("input.txt", n, m);
	printMatrix(m);
}