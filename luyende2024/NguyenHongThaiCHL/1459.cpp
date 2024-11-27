#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e7)];
bool vis[int(1e7)];
int chiphi=0,soloai=0;
vector<int> ans;
int pos[int(1e7)];

void prim(pair<int,int> s)
{
    memset(vis,false,sizeof(vis));
    memset(pos,int(1e7),sizeof(pos));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    while (q.empty()==false)
    {
        auto it = q.top();
        int u=q.top().second;
        pos[u]=min(pos[u],it.first);
        for(auto v:inp[u]){
            if(vis[v.second]==false){
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
        int u,v,c;
        cin>>u>>v>>c;
        inp[u].push_back({c,v});
        inp[v].push_back({c,u});
    }
    prim({0,1});
    if(soloai==0) cout<<-1;
    else{
        cout<<chiphi<<" "<<soloai<<endl;
        for(auto x:ans) cout<<x<<endl;
    }
    
}