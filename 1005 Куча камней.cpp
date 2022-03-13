#include <iostream>
#include <algorithm>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define endl "\n"
#define pll pair <ll,ll>
#define next yamogu
typedef long long ll;
const int MAXINT = 2147483640;
const ll MAXLL = 9223372036854775800LL;
const ll MAXN = 1e6;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[MAXN], old[4 * MAXN + 100], next[4 * MAXN + 100];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    old[2 * MAXN] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 4 * MAXN; ++j) {
            if (j + a[i] <= 4 * MAXN && old[j]) {
                next[j + a[i]] |= old[j];
            }
            if (j - a[i] >= 0 && old[j]) {
                next[j - a[i]] |= old[j];
            }
        }
        for (int j = 0; j <= 4 * MAXN; ++j) {
            old[j] = next[j];
            next[j] = 0;
        }
    }
    ll mx = MAXLL;
    for (int i = 0; i <= 4 * MAXN; ++i) if (old[i]) {
        mx = min(abs(i - 2 * MAXN), mx);
    }
    cout << mx << endl;
    return 0;
}