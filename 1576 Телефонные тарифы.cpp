#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N1, C1, N2, limit, C2, N3, n, time = 0, mins, secs, ans;
    cin >> N1 >> C1    >> N2 >> limit >> C2 >> N3 >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d", &mins, &secs);
        ans = mins * 60 + secs;
        time += ans > 6 ? (ans + 59) / 60 : 0;
    }
    cout << "Basic:     " << N1 + time*C1 << '\n'
         << "Combined:  " << N2 + max(time - limit, 0) * C2 << '\n'
         << "Unlimited: " << N3;
}