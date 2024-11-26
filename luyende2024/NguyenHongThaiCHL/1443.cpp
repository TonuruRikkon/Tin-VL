#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(1e5)+5;
vector<int> inp[MAXN];
bool vis[MAXN];
vector<pair<int,int>> mst_Edges;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:inp[u]){
            if(!vis[v]){
                vis[v]=true;
                mst_Edges.push_back({u,v});
                q.push(v);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    fill(vis,vis+n+1,false);
    bfs(1);
    cout<<mst_Edges.size()<<endl;
    for(auto x:mst_Edges){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return 0;
}