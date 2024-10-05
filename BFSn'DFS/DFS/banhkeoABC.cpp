#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans=0;
bool visited[100000];
vector<int> P,adj[int(1e6)+1];

void dfs(int s)
{
    visited[s]=true;
    for(int x:adj[s]){
        if(!visited[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    memset(visited,false,sizeof(visited));
    cin>>n>>m>>k;
    int minn=501;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        if(x<minn) minn=x;
        P.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        if(t>=minn){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
}