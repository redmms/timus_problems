#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> mas(n);
    for (int i = 0; i <= n - 1; i++) {
        cin >> mas[i];
    }

    long long int maxS = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mas[i];
        if (sum > maxS)
            maxS = sum;
        else if (sum < 0) 
            sum = 0;
    }

    cout << maxS;
}