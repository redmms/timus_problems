#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
 
#define F first
#define S second
#define ll long long
#define len length()             
#define sqr(x) x*x
#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define bp(x) __builtin_popcount(x)            
#define INF numeric_limits<long long int>::max()
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define frp freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
 
const int maxn = (int)1e6;
const int mod = (int)1e9 + 7;
 
using namespace std;
 
int n;
__int64 mx=-1,ans,x;
map<ll,ll> m;
 
int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d",&n);
	for(int i=0; i < n; i++){
		scanf("%I64d",&x);
		m[x]++;
	}
	for(map<ll,ll>::iterator it=m.begin(); it != m.end(); it++){
		if((*it).S > mx){
			mx=(*it).S;
			ans=(*it).F;
		}	
	}
	printf("%I64d\n",ans);	
 
    return 0;
}