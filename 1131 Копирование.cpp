#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    //ceil

    long long s = int(log2(k))+1;

    if ( n-pow(2,s)>0)
    s = s + ceil((n-pow(2,s))/k);
    else
    s = int(ceil((log2(n))));
    cout<<s;

}