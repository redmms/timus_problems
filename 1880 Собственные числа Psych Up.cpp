#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool my_greater(vector <int> & a, vector <int> & b) { 
	return a.size() > b.size();
}


int main() {
	int n, i, j, MAX, ans =0;
	vector < vector <int> > vec(3, vector <int>(4000));
	vector <int> obsh(4000);

	for (i = 0; i < 3; i++) {
		cin >> n;
		vec[i].resize(n);
		for (j = 0; j < n; j++) {

			cin >> vec[i][j];
		}
	}

	//MAX = max(max(vec[0].size(), vec[1].size()), vec[2].size());
	//obsh.resize(MAX);
	//sort(vec.begin(), vec.end(), my_greater);
	copy(vec[0].begin(), vec[0].end(), obsh.begin());

	for (int j = 0; j < obsh.size(); j++) {
		if (!binary_search(vec[1].begin(), vec[1].end(), obsh[j]) ||
			!binary_search(vec[2].begin(), vec[2].end(), obsh[j])) {
			obsh.erase(obsh.begin() + j);
			j--;
		}
	}

	cout << obsh.size();
}
    