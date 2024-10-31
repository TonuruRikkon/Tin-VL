#include <bits/stdc++.h>
using namespace std;

bool visited[int(1e6)+1];
int steps[int(1e6)+1],trace[int(1e6)+1];

void bfs(int s,vector<vector<pair<int,int>>> adj)
{
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false){
        int checking=q.front();
        for(auto x:adj[checking]){
            if(visited[x.first]==false){
                q.push(x.first);
                steps[x.first]=steps[checking]+x.second;
                trace[x.first]=checking;
                visited[x.first]=true;
            }
        }
        q.pop();
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    
}