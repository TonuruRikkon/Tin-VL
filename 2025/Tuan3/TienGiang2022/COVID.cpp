#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj,vector<int> &path, const int &s)
{
    int vis[adj.size()+1];
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=true;
    path[s]=0;
    while (q.empty()==false)
    {
        int u=q.front();
        vis[u]=true;
        q.pop();
        for (int v : adj[u])
        {
            if(path[v]>path[u]+1){
                path[v]=path[u]+1;
            }
            if(!vis[v]){
                q.push(v);
            }
        }
        
    }
    

}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        scanf("%d", &u);
        scanf("%d", &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        if(i!=0) printf("%c",'\n');
        int s,d;
        scanf("%d", &s);
        scanf("%d", &d);
        vector<int> path(n+1,INT_MAX);
        bfs(adj,path,s);
        printf("%d",path[d]);
    }
    
}