#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
int N,M;
vector<int> adj[10001];
vector<string> ans;
string an1 = "";

void dfs(int u)
{
    visited[u]=true;
    for(int x:adj[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int dem()
{
    int d=0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; i++)
    {
        if(!visited[i]){
            dfs(i);
            d++;
        }
    }
    return d;
}

int main()
{
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<dem();
    
}