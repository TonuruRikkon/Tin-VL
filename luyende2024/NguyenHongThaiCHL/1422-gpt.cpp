#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 10;
vector<int> adj[MAXN];
bool visited[MAXN];

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
                q.push(v);
            }
        }
    }
}

bool is_connected(int n) {
    memset(visited, false, sizeof(visited));
    bfs(0); // Bắt đầu từ nhà của Granny (đỉnh 0)
    for (int i = 0; i <= n; i++) {
        if (!visited[i] && !adj[i].empty()) {
            return false;
        }
    }
    return true;
}

bool has_eulerian_circuit(int n) {
    if (!is_connected(n)) {
        return false;
    }
    for (int i = 0; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }

    if (has_eulerian_circuit(n)) {
        cout << "Granny can make the circuit." << endl;
    } else {
        cout << "Granny can not make the circuit." << endl;
    }

    return 0;
}
