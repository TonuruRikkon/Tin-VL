#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<pair<int, int>> mst_edges;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                mst_edges.push_back({u, v});
                q.push(v);
            }
        }
    }
}

int main() {
    freopen("test12.in", "r", stdin);
    freopen("testout.out", "w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(visited, visited + n + 1, false);
    bfs(1); // Bắt đầu từ đỉnh 1

    cout << mst_edges.size()<<endl;
    for (auto edge : mst_edges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}
