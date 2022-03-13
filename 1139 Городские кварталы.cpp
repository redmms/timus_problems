#include <iostream>
#include <algorithm>
using namespace std;
long gcd(long a, long b) {

    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}
int main() {
    long mx, my, ans, ansl;
    cin >> mx >> my;
    mx--; my--;
    long MAX = max(mx, my); long MIN = min(mx, my);
    mx = MAX; my = MIN;
    long GCD = gcd(mx, my);
    if (GCD == my)
        ans = mx;
    else {
        my /= GCD; mx /= GCD;
        ans = my - 1 + mx;
        ans *= GCD;
    }
    cout << ans;
}