#include <bits/stdc++.h>
using namespace std;

bool vis[int(1e6)+1];
vector<int> adj[int(1e6)+1];
int moved[int(1e6)+1];

void bfs(int s)
{
    memset(vis,false,sizeof(vis));
    memset(moved,0,sizeof(moved));
    queue<int> q;
    q.push(s);
    vis[s]=true;
    moved[s]=0;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]==false){
                q.push(v);
                vis[v]=true;
                moved[v]=moved[u]+1;
            }
        }
    }
}

int main()
{
    freopen("MAZE.INP","r",stdin);
    freopen("MAZE.OUT","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>> inp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        string str_inp;
        cin>>str_inp;
        for(int j=0;j<=n;j++){
            if(str_inp[j]=='1'){
                adj[i].push_back(j);
            }
        }
    }
    bfs(0);
    cout<<round(float(moved[n-1])/2);

}
