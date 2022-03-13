#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    double n, t, s;
    cin >> n >> t >> s;
    double opposite[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> opposite[i];
        if (opposite[i] >= s)
        {
            cout << fixed << setprecision(6) << ((opposite[i] + (s + t)) / 2) << endl;
        }
        else
        {
            cout << fixed << setprecision(6) << ((s + (opposite[i] + t)) / 2) << endl;
        }
    }

}