#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector <vector <int>> g(N);
    int h;
    for (int i = 0; i < N; i++) {
        for (;;) {
            cin >> h;
            if (!h)
                break;
            g[i].push_back(h - 1);
        }
    }
    int n = g.size();
    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n);
    int start = 0; int s;
    auto bfs = [&](int start) {
        s = start;
        q.push(s);
        used[s] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (size_t i = 0; i<g[v].size(); ++i) {
                int to = g[v][i];
                if (!used[to]) {
                    used[to] = true;
                    q.push(to);
                    d[to] = d[v] + 1;
                }
            }
        }
    };
    for (int start = 0; start < n; ++start)
        if (!used[start]) {
            bfs(start);
        }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (d[i] % 2 == 0)
            ans.push_back(i + 1);
    }
    int size = ans.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++)
        cout << ans[i] << " ";
}