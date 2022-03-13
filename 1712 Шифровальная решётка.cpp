#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <vector <char>> reshor(4, vector <char>(4)), par(4, vector <char>(4)), resh(4, vector <char>(4));
void rot() {
    for (int i = 0, j2 =0; i < 4; i++, j2++)
         for (int j = 0, i2 = 3; j < 4; j++, i2--) 
                    resh[i][j] = reshor[i2][j2];
    reshor = resh;
}
int main() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cin >> reshor[i][j];
            resh[i][j] = reshor[i][j];
        }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> par[i][j];
    string ans;
    for (int a = 0; a < 4; a++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (resh[i][j] == 'X')
                    ans.push_back(par[i][j]);
        rot();
    }
    cout << ans;
}