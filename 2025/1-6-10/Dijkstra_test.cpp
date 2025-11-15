#include <bits/stdc++.h>
using namespace std;

void Dijkstra(const vector<vector<pair<int,int>>> &adj, vector<long long> &dist, int n, int s)
{
    const long long INF = (1LL<<62);
    dist.assign(n+1, INF);
    dist[s] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // stale entry
        for (auto &e : adj[u]) {
            int v = e.first;
            long long w = e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DIJ.INP","r",stdin);
    freopen("DIJ.OUT","w",stdout);
    int n,m;
    if (!(cin>>n>>m)) return 0;
    vector<vector<pair<int,int>>> inp(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        inp[u].push_back({v,w});
        inp[v].push_back({u,w});
    }
    vector<long long> dist;
    Dijkstra(inp, dist, n, 1);

    const long long INF = (1LL<<62);
    for (int i = 1; i <= n; ++i)
    {
        if (i>1) cout << ' ';
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
    }
    cout << '\n';
    return 0;
}