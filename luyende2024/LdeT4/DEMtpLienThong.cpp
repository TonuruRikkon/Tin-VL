#include <bits/stdc++.h>
using namespace std;

bool visited[int(1e6)+1];
vector<int> inp[int(1e6)+1];

void dfs(int s)
{
    visited[s]=true;
    int u=s;
    for(int v:inp[u]){
        if(visited[v]==false){
            dfs(v);
        }
    }
}

int main()
{
    memset(visited,false,sizeof(visited));
    int n,m,ans=0;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]==false){
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
}