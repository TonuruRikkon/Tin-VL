#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> inp[256];
int steps[256];

void Dijkstra(char s) {
    memset(steps, 0x3f, sizeof(steps));
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> q;
    q.push({0, s});
    steps[s] = 0;
    while (!q.empty()) {
        auto topp = q.top();
        int u = topp.second;
        int d = topp.first;
        q.pop();
        if (d > steps[u]) continue;
        for (auto v : inp[u]) {
            if (steps[v.second] > steps[u] + v.first) {
                steps[v.second] = steps[u] + v.first;
                q.push({steps[v.second], v.second});
            }
        }
    }
}

int main() {
    int p;
    cin >> p;
    vector<char> bo;
    for (int i = 0; i < p; i++) {
        char u, v;
        int c;
        cin >> u >> v >> c;
        if (u >= 'A' && u <= 'Y') bo.push_back(u);
        if (v >= 'A' && v <= 'Y') bo.push_back(v);
        inp[u].push_back({c, v});
        inp[v].push_back({c, u});
    }
    Dijkstra('Z');
    char bonhat = 0;
    int ans = INT_MAX;
    for (char x : bo) {
        if (ans > steps[x]) {
            ans = steps[x];
            bonhat = x;
        }
    }
    cout << bonhat << " " << ans << endl;
    return 0;
}
