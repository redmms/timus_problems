#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string sh4;
    cin >> sh4;
    int sz = sh4.size();
    vector <int> sh3;
    for (int i = 0; i < sz; i++)
        sh3.push_back(sh4[i] - 97);
    //sh2
    bool nrep = false;
    do {
        nrep = false;
        for (int i = 0; i < sz - 1; i++)
            if (sh3[i + 1] < sh3[i] || sh3[i + 1] < 5) {
                sh3[i + 1] += 26;
                nrep = true;
            }
    } while (nrep == true);
    if (sh3[0] < 5)
        sh3[0] += 26;
    for (int i = sz - 1; i >= 1; i--) {
        sh3[i] = sh3[i] - sh3[i - 1];
    }
    sh3[0] -= 5;
    for (int i = 0; i < sz; i++)
        cout << char(sh3[i] + 97);
}