#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool visited[MAXN];
int timer;
vector<int> articulation_points;
vector<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
            if (low[to] >= tin[v] && p != -1)
                articulation_points.push_back(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        articulation_points.push_back(v);
}

void find_articulation_points_and_bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        tin[i] = -1;
        low[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_articulation_points_and_bridges(n);
    cout << "Articulation points:\n";
    for (int point : articulation_points) {
        cout << point << " ";
    }
    cout << "\nBridges:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " " << bridge.second << "\n";
    }
    return 0;
}
