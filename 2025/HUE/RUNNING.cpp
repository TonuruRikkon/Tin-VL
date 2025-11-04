#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const long long INF = 1e18;

vector<pair<int, int>> adj[MAXN];

// To store results from DFS from start_node s
long long dist_from_s[MAXN];
int nodes_on_path_from_s[MAXN];

void dfs(int u, int p, long long current_dist, int current_depth) {
    dist_from_s[u] = current_dist;
    nodes_on_path_from_s[u] = current_depth + 1;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (v != p) {
            dfs(v, u, current_dist + weight, current_depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s;
    cin >> n >> k >> s;

    // Initialize distances and depths
    for (int i = 1; i <= n; ++i) {
        dist_from_s[i] = -1;
        nodes_on_path_from_s[i] = 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 1. Run DFS from the start node s
    dfs(s, 0, 0, 0);

    // 2. Find the minimum length path that visits at least k nodes
    long long min_len = INF;
    for (int i = 1; i <= n; ++i) {
        if (nodes_on_path_from_s[i] >= k) {
            min_len = min(min_len, dist_from_s[i]);
        }
    }

    if (min_len == INF) {
        // This case happens if no path from s has at least k nodes (e.g., n < k).
        // Output -1 or handle as per problem specification for no solution.
        cout << -1 << endl;
    } else {
        cout << min_len << endl;
    }

    return 0;
}