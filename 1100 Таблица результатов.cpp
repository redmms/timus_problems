#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;
 
int main(){
	int N, ID, M;
	cin >> N;
	vector <pair <int, int>> vec(N);
	int a, b;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		vec[i] = make_pair(a, b);
	}
	stable_sort(vec.begin(), vec.end(), [](pair <int, int> const &lhs, pair<int, int> const &rhs) { 
		return lhs.second > rhs.second; });
	for (int i = 0; i < N; i++){
		cout << vec[i].first << " " << vec[i].second << '\n';
	}
}