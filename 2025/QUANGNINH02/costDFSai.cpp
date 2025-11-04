#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;
vector<pair<int,int>> adj[N];
ll t[N], cnt[N], d[N];
ll total = 0;
int n;
ll k;

void dfs1(int u, int p) {
    cnt[u] = t[u];
    for (auto [v, w] : adj[u]) if (v != p) {
        dfs1(v, u);
        cnt[u] += cnt[v];
        d[1] += 1LL * cnt[v] * w;
    }
}

void dfs2(int u, int p) {
    for (auto [v, w] : adj[u]) if (v != p) {
        d[v] = d[u] + 1LL * (total - 2 * cnt[v]) * w;
        dfs2(v, u);
    }
}

int main() {
    cin >> n >> k;
    for (int i=1; i<n; ++i) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    for (int i=1; i<=n; ++i) {
        cin >> t[i];
        total += t[i];
    }

    dfs1(1, 0);  // lượt 1
    dfs2(1, 0);  // lượt 2

    ll minCost = LLONG_MAX, maxCost = LLONG_MIN;
    for (int i=1; i<=n; ++i) {
        minCost = min(minCost, d[i]);
        maxCost = max(maxCost, d[i]);
    }

    cout << minCost << " " << maxCost << " ";
    if (k < minCost) cout << "NO";
    else if (k <= maxCost) cout << "YES";
    else cout << "GOOD";
}