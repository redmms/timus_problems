#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long n, sum = 0;
    cin >> n;
    vector <int> xCoords(n), 
				 yCoords(n);
    for (long long i = 0; i < n; i++){
        cin >> xCoords[i] >> yCoords[i];
    }
    sort(xCoords.begin(), xCoords.end());
    sort(yCoords.begin(), yCoords.end());
    for (long long i = 1; i < n; i++){
        sum += ((xCoords[i] - xCoords[i - 1]) + (yCoords[i] - yCoords[i - 1])) * i * (n - i) * 2;
    }
    sum /= n * (n - 1);
    cout << sum << endl;
}