#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int sum(int a){
    int sum = 0;
    while(a!=0)
 { 
    sum += a%10;
    a/=10;
 } 
 return sum;
}

int main (){
    int f, l, a; string fs, ls;
    cin >> a;
    int apl = a + 1, fpl = apl/1000, lpl = apl%1000, amns = a - 1, fmns = amns/1000, lmns = amns%1000;
    if (sum(fpl) == sum(lpl) || sum(fmns) == sum(lmns))
        cout << "Yes";
    else
        cout << "No";
}