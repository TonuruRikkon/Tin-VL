#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj,vector<bool> &vis , vector<vector<int>> &cnt,vector<int> &col)
{
    vis[u]=true;
    for (int v : adj[u])
    {
        if(vis[v]==false){
            dfs(v,adj,vis,cnt,col);
            int sz=cnt[v].size();
            for (int i = 0; i < sz; i++)
            {
                cnt[u][i]+=cnt[v][i];
            }
            
        }
    }
    cnt[u][col[u]]++;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> col(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin>>col[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    vector<vector<int>> cnt(n+1,vector<int>(n+1,0));
    dfs(1,adj,vis,cnt,col);
    for (int i = 0; i < q; i++)
    {
        int u,k;
        cin>>u>>k;
        int temp=0;
        for(int x:cnt[u]){
            if(x==k) temp++;
        }
        cout<<temp<<'\n';
    }
    
}