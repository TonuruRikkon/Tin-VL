#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &cnt,vector<pair<int,int>> &edge)
{
    cnt[u]=1;
    for (int v : adj[u])
    {
        if(v!=p){
            edge.push_back({u,v});
            dfs(v,u,adj,cnt,edge);
            cnt[u]+=cnt[v];
        }
    }
    
}

void delta(int n1,int n2,int n3,int &ans){
    int maxx=max({n1,n2,n3});
    int minn=min({n1,n2,n3});
    ans=min(ans,maxx-minn);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    vector<int> cnt(n+1,0);
    vector<pair<int,int>> edge;
    dfs(1,0,adj,cnt,edge);
    int sz=edge.size();

    int ans=INT_MAX;

    for (int i = 0; i < sz; i++)
    {
        int v1=edge[i].second;
        int N1=cnt[v1];
        for (int j = i+1; j < sz; j++)
        {
            int u2=edge[j].first;
            int v2=edge[j].second;
            int N2=cnt[v2];
            if(u2==v1){
                delta(N2,N1-N2,n-N1,ans);
            }
            else{
                delta(N1,N2,n-N1-N2,ans);
            }
        }
        
    }
    cout<<ans;
}