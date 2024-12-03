#include <bits/stdc++.h>
using namespace std;

//De Bai: tìm con đương ngắn nhất của một cây có trọng số

vector<pair<int,int>> adj[int(1e6)];
vector<bool> vis(int(1e6),false);
vector<int> moved(int(1e6));

void Dijkstra(pair<int,int> s)
{
    fill(vis.begin(),vis.end(),false);
    priority_queue<pair<int,int>> q;
    q.push(s);
    vis[s.second]=true;
    moved[s.second]=s.first;
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=topp.second;
        q.pop();
        for(auto v:adj[u]){
            if(vis[v.second]==false){
                q.push(v);
                moved[v.second]=moved[u]+v.first;
                vis[v.second]=true;
            }
        }
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
    }
    Dijkstra({0,1});
    cout<<moved[2];
}