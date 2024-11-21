#include<bits/stdc++.h>
using namespace std;

bool visited[int(1e6)+1];
vector<int> tso(int(1e6)+1,0),inp[int(1e6)+1];

void bfs(int s)
{
    memset(visited,false,sizeof(visited));  
    queue<int> q;
    visited[s]=true;
    
}

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>tso[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    
}