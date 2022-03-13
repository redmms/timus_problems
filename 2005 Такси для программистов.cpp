#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int a[6][6];
    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 6; j++)
        {
            cin >> n;
            a[i][j] = n;
        }

    int S1, S2, S3, S4;
    S1 = a[1][2] + a[2][3] + a[3][4] + a[4][5];
    S2 = a[1][3] + a[3][2] + a[2][4] + a[4][5];
    S3 = a[1][3] + a[3][4] + a[4][2] + a[2][5];
    S4 = a[1][4] + a[4][3] + a[3][2] + a[2][5];

    int MIN = min(S1, min(S2, min(S3, S4)));
    if (MIN == S1)
        cout << S1 << endl << "1 2 3 4 5" << endl;

    else if (MIN==S2)
        cout << S2 << endl << "1 3 2 4 5" << endl;

    else if (MIN ==S3)
        cout << S3 << endl << "1 3 4 2 5" << endl;

    else if (MIN==S4)
        cout << S4 << endl << "1 4 3 2 5" << endl;
}