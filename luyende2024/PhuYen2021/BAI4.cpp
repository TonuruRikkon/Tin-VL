#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[101];
bool vis[101];
int pos[int(101)],from[101];

void dijkstra(pair<int,int> s)
{
    memset(from,0,sizeof(from));
    memset(pos,0,sizeof(pos));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    vis[s.second]=true;
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=q.top().second;
        q.pop();
        vis[u]=true;
        for(auto v:inp[u]){
            if(vis[v.second]==false){
                pos[v.second]=pos[u]+v.first;
                from[v.second]=u;
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
    int s,e;
    cin>>s>>e;
    dijkstra({0,s});
    cout<<pos[e]<<endl;
    int ch=e;
    vector<int>ans;
    while (from[ch]!=0)
    {
        ans.emplace(ans.begin(),ch);
        ch=from[ch];
    }
    cout<<ans.size()+1<<" "<<s<<" ";
    for(int x:ans){
        cout<<x<<" ";
    }
}