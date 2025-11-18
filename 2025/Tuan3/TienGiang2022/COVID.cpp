#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n; i++)
    {
        int u,v;
        scanf("%d", &u);
        scanf("%d", &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}