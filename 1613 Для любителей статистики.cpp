#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef set<int> sint;
typedef unordered_map<int,vector<int>> misint;
 
misint nums;
 
int main()
{
cin.sync_with_stdio(false);
cin.tie(0);
   int n;
cin >> n;
  // scanf( "%d", &n );
   int ai;
   for( int i = 1; i <= n; i++ )
   {
cin >> ai;
     // scanf( "%d", &ai );
      nums[ ai ].push_back( i );
   }
for (auto & [k,v] : nums)
    sort(v.begin(), v.end());
   int q;
cin >> q;
   //scanf( "%d", &q );
   int l, r, x;
   for( int i = 0; i < q; i++ )
   {
cin>>l>>r>>x;
     // scanf( "%d%d%d", &l, &r, &x );
      auto& positions = nums[ x ];
      auto lb = 
lower_bound(positions.begin(), positions.end(), l);
//positions.lower_bound( l );
      if( lb != positions.end() && *lb <= r )
cout<<1;
        // putchar( '1' );
      else
cout<<0;
       //  putchar( '0' );
   }
}