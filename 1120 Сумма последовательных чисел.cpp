#include <iostream>
using namespace std;
int main() {
    long long n, P; long double A;
    cin >> n;
    for (P = ceil(sqrt(2*n)); P >= 1; P--) {
        A = (2 * n - P * P + P) / (2 * P);
        if (A == round(A) && 2*n == P*P+P*(2*A-1) && A > 0)
            break;
    }
    cout << long long (A) << " " << P;
}