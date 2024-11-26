#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(1e7)];
bool vis[int(1e7)];
vector<pair<int,int>> Edges;

void bfs(int s)
{
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:inp[u]){
            if(vis[v]==false){
                vis[v]=true;
                q.push(v);
                Edges.push_back({u,v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    
    bfs(1);
    cout<<Edges.size()<<endl;
    for(auto x:Edges){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
}