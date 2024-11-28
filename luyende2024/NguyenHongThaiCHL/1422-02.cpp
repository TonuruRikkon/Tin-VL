#include <bits/stdc++.h>
using namespace std;

vector<int> inp[10];
vector<bool> vis(10);
vector<int> tim(10,0), low(10,0);
int timer = 0;

bool dfs(int s, int father) {
    int u = s, child = 0;
    vis[u] = true;
    tim[u] = low[u] = timer++;
    for (auto v : inp[u]) {
        if (v == father) continue;
        if (!vis[v]) {
            if (!dfs(v, u)) return false;
            low[u] = min(low[u], low[v]);
            if (low[v] >= tim[u] && father != -1) return false;
            child++;
        } else {
            low[u] = min(low[u], tim[v]);
        }
    }
    if (child > 1 && father == -1) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string str;
        getline(cin, str);
        for (char x : str) {
            if (x != ' ') {
                inp[i].push_back(x - '0');
                inp[x - '0'].push_back(i);
            }
        }
    }
    if (dfs(1, -1)) cout << "Granny can make the circuit.\n";
    else cout << "Granny can not make the circuit.\n";
}
