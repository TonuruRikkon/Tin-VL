#include <bits/stdc++.h>
using namespace std;

bool visited[2*int(1e5)+1];
int n,m,x,ans=0;
vector<int> adj[2*int(1e5)+1];

void dfs(int s)
{
    visited[s]=true;
    for(int x:adj[s]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    cin>>n>>m>>x;
    for (int i = 0; i < m; i++)
    {
        int u,v,c ;
        cin>>u>>v>>c;
        if(c>=x){
            adj[u].push_back(v);
            adj[v].push_back(u);
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