#include <iostream>
#include <string>
using namespace std;
int main(){
string s, t;
cin >>s;
int Len = s.length();
for (int i =0; i<Len; i++){
if (t.empty() || t.back() != s[i])
  t.push_back(s[i]);
else
  t.pop_back();
}
cout<<t;
}