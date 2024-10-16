#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(int(1e5), false);
int ans=0;
vector<int> inp,adj[int(1e5)];

void dfs(int s, vector<int> adj[int(1e5)],vector<int> inp,int index,int father){
    int u=s;
    int v;
    for(int x:adj[u]){
        if(x!=father){
            v=x;
            dfs(x,adj,inp,index++,s);
        }
        
    }
    if(index*min(inp[u],inp[v])>ans) ans=index*min(inp[u],inp[v]);
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(0,adj,inp,1,0);
    cout<<ans;
}