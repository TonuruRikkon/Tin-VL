#include <bits/stdc++.h>
using namespace std;

void DPonTree(int u, vector<int> &sal, vector<vector<int>> &adj, vector<int> &dp0, vector<int> &dp1)
{
    dp1[u]=1;
    dp0[u]=0;
    for(int v:adj[u]){
        DPonTree(v,sal,adj,dp0,dp1);
        dp0[u]+=max(dp0[v],dp1[v]);
        dp1[u]+=(sal[u]>sal[v]) ? max(dp0[v],dp1[v]):dp0[v];       
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> inp(n+1,0);
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>inp[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i+1);
    }
    
    vector<int> dp0(n+1);
    vector<int> dp1(n+1);
    DPonTree(1,inp,adj,dp0,dp1);
    
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        cout<<max(dp0[x],dp1[x])<<'\n';
    }    
}