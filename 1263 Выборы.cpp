#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main() {
	int N, M, a;
	cin >> N >> M;
	vector <float> list(N);
	for (int i = 0; i < M; i++) {
		cin >> a;
		list[a-1]++;
	}
	float sum = accumulate(list.begin(), list.end(), 0.0);
	for (int i = 0; i < N; i++) {
		list[i] = list[i]/sum*100;
		cout.setf(ios::fixed);
		cout <<setprecision(2) << list[i] << "%" << '\n';
	}
}