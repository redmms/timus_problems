#include <iostream>
#include <algorithm>
using namespace std;    
int dp[1001][1001];
bool Diag[1001][1001];
int main() {
    int maxX, maxY, K, X, Y;
    cin >> maxX >> maxY >> K;
    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        Diag[X][Y] = true;
    }
    for (int x = 1; x <= maxX; ++x)
        for (int y = 1; y <= maxY; ++y) 
             dp[x][y] = max(max(dp[x - 1][y], dp[x][y - 1]), dp[x - 1][y - 1] + int(Diag[x][y]));
    int maxKolD = dp[maxX][maxY];
    cout << round(maxKolD*sqrt(20000) + (maxX - maxKolD) * 100 + (maxY - maxKolD) * 100);
}