#include <iostream>
#include <vector>
using namespace std;
#define re return
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sqrt(x) sqrt(abs(x))
#define mp make_pair
#define pi (3.14159265358979323846264338327950288419716939937510)
#define fo(i, n) for(int i = 0; i < n; ++i)
#define ro(i, n) for(int i = n - 1; i >= 0; --i)
#define unique(v) v.resize(unique(all(v)) - v.begin())

template <class T> T abs(T x) { re x > 0 ? x : -x; }
template <class T> T sqr(T x) { re x * x; }
template <class T> T gcd(T a, T b) { re a ? gcd(b % a, a) : b; }
template <class T> int sgn(T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef unsigned long long ull;

double calc() {
	int a, b;
	cin >> a >> b;
	if (a == 1) re b * 2;
	if (a == 2) re b;
	re sqrt(3) * b / 2.0;
}

int main() {
	int ans = 0, a, b;
	double fuck;
	cin >> a >> b;
	if (a == 1) fuck = b * 2;
	if (a == 2) fuck = b * sqrt(2);
	if (a == 3) fuck = b;
	int n;
	cin >> n;
	fo(i, n) {
		if (calc() <= fuck) ++ans;
	}
	cout << ans << endl;
}