#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    cout << int(n*(n - 1) / 2) - k;
}