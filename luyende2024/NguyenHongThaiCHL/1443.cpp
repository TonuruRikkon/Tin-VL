#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(1e6)+1];
bool vis[int(1e6)+1];
int tim[int(1e6)+1],low[int(1e6)+1];
int timer=0;
vector<pair<int,int>> bridges,outp;

void dfs(int s,int father)
{
    int u=s;
    vis[u]=true;
    tim[u]=low[u]=++timer;
    for(int v:inp[u]){
        if(v==father) continue;
        if(vis[v]==false){
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>tim[u]) bridges.push_back({u,v});
        }
        else{
            low[u]=min(low[v],low[u]);
        }
    }
}

void remove_bridges() 
{ 
    for (auto bridge : bridges) { 
        int u = bridge.first;
        int v = bridge.second;
        inp[u].erase(remove(inp[u].begin(), inp[u].end(), v), inp[u].end());
        inp[v].erase(remove(inp[v].begin(), inp[v].end(), u), inp[v].end()); 
    } 
} 
void print_tree(int u, int father) 
{
    vis[u] = true; cout << u << " ";
    for (int v : inp[u]) 
    {
        if (v != father && !vis[v])
        {
            print_tree(v, u);
        } 
    }
}

int main()
{
    memset(vis,false,sizeof(vis));
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
        outp.push_back({u,v});
    }
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]==false){
            dfs(i,-1);
        }
    }
    cout<<endl;
    remove_bridges();
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<" ";
        for(int x:inp[i]) cout<<x<<" ";
        cout<<endl;
    }
    
    
}