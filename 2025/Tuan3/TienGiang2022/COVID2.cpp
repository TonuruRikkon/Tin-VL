#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_LOG = 20; 
int n; 
vector<vector<int>> adj; 
vector<int> depth; 
vector<vector<int>> P; 

// Hàm tìm tổ tiên thứ k của u (dùng Binary Lifting)
int get_k_th_ancestor(int u, int k) {
    if (k < 0) return 0; // Xử lý lỗi nếu k âm
    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (u == 0) break;
        if (k & (1 << i)) {
            u = P[u][i];
            k -= (1 << i);
        }
    }
    return u;
}

void dfs_preprocess(int u, int parent, int d) {
    depth[u] = d;
    P[u][0] = parent; 
    for (int v : adj[u]) {
        if (v != parent) {
            dfs_preprocess(v, u, d + 1); 
        }
    }
}

void build_binary_lifting_table() {
    for (int k = 1; k < MAX_LOG; ++k) {
        for (int u = 1; u <= n; ++u) {
            P[u][k] = P[P[u][k - 1]][k - 1];
        }
    }
}

int find_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // Leveling
    int diff = depth[u] - depth[v];
    for (int k = MAX_LOG - 1; k >= 0; --k) {
        if ((diff >> k) & 1) { 
            u = P[u][k];
        }
    }

    if (u == v) return u;

    // Simultaneous Jump
    for (int k = MAX_LOG - 1; k >= 0; --k) {
        if (P[u][k] != P[v][k]) {
            u = P[u][k];
            v = P[v][k];
        }
    }
    return P[u][0];
}

void solve() {
    int m;
    if (!(cin >> n)) return;

    adj.resize(n + 1);
    depth.resize(n + 1);
    P.assign(n + 1, vector<int>(MAX_LOG, 0));

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Đọc số lượng truy vấn
    if (!(cin >> m)) return;

    // Tiền xử lý
    int root = 1; 
    dfs_preprocess(root, root, 0); 
    build_binary_lifting_table();

    for (int i = 0; i < m; ++i) {
        int s, d;
        cin >> s >> d;
        int l = find_lca(s, d);
        int r; // Khu phố tiếp nối cần tìm

        if (l == s) {
            // Case 1: s là tổ tiên của d. Đường đi: s -> r -> ... -> d
            // r là tổ tiên của d cách d (Depth[d] - Depth[s] - 1) bước
            int steps = depth[d] - depth[s] - 1;
            r = get_k_th_ancestor(d, steps);
            
        } else {
            // Case 2 & 3: d là tổ tiên của s HOẶC l là tổ tiên chung trên cao.
            // Đường đi: s -> r -> ... -> l -> ... -> d
            // r là cha trực tiếp của s (tổ tiên thứ 1 của s)
            r = get_k_th_ancestor(s, 1); 
        }

        cout << r << "\n";
    }
}

// Hàm main để đọc từ tệp COVID.INP và ghi ra COVID.OUT
int main() {
    // Để mô phỏng việc đọc/ghi file
    freopen("COVID.INP", "r", stdin);
    freopen("COVID.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}