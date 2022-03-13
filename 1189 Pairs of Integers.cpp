#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

int p[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
int num[10];
std::vector<int> ans;

void postSkip(int l, int carry, int res)
{
    if(l == -1)
    {
        if(!carry)
            ans.push_back(res);
        return;
    }
    int X = carry*10 + num[l];
    int Y = X/2;
    if(X % 2 == 0)
        postSkip(l-1, 0, res + p[l]*Y);
    Y = (X - 1)/2;
    if((X - 1) % 2 == 0)
        postSkip(l-1, 1, res + p[l]*Y);
}

void preSkip(int l, int carry, int X, int res)
{
    if(l == -1)
        return;
    int Z = carry*10 + num[l];
    int Y = Z - X;
    if(Y >= (!res ? 1 : 0) && Y < 10)
    {
        preSkip(l-1, 0, Y, res + p[l]*Y);
        postSkip(l-1, 0, res + p[l]*Y);
    }
    Y = Z - X - 1;
    if(Y >= (!res ? 1 : 0) && Y < 10)
    {
        preSkip(l-1, 1, Y, res + p[l]*Y);
        postSkip(l-1, 1, res + p[l]*Y);
    }
}

int main()
{
    int n;
    std::cin >> n;
    
    int i = 0;
    for(int k = n; k; k /= 10, i++)
        num[i] = k % 10;
    preSkip(i-1, 0, 0, 0);
    if(num[i-1] == 1)
        preSkip(i-2, 1, 0, 0);
    std::sort(ans.begin(), ans.end());
    int size = std::unique(ans.begin(), ans.end()) - ans.begin();
    std::cout << size << "\n";
    for(int j = 0; j < size; j++)
        std::cout << ans[j] << " + " << std::setfill('0') 
                  << std::setw(std::to_string(ans[j]).length()-1) 
                  << (n-ans[j]) << " = " << n << "\n";
}