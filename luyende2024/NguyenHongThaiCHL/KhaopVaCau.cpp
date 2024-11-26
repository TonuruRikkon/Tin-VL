#include <bits/stdc++.h>
using namespace std;

//http://nguyenhongthai.io.vn/coj/problem.php?cid=1941&pid=0

vector<int> inp[int(1e6)+1];
bool vis[int(1e6)+1];
int tin[int(1e6)+1],low[int(1e6)+1];
int timer=1;
vector<pair<int,int>> bringes;
vector<int> DinhKhop;

void dfs(int s,int father)
{
    int u=s,child=0;
    vis[u]=true;
    low[u]=tin[u]=timer;
    timer++;
    for(auto v:inp[u]){
        if(v==father) continue;
        if(vis[v]==false)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>tin[u]) bringes.push_back({min(u,v),max(u,v)});
            if(low[v]>=tin[u]&&father!=-1) {
                DinhKhop.push_back(u);
            }    
            child++;
        } 
        else{
            low[u] = min(low[u],low[v]);
        }
    }
    if(child>1&&father==-1) DinhKhop.push_back(u);
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
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i,-1);
    }
    sort(DinhKhop.begin(),DinhKhop.end());
    cout<<DinhKhop.size()<<endl;
    for (int i = 0; i < DinhKhop.size(); i++)
    {
        cout<<DinhKhop[i]<<" ";
    }
    cout<<endl<<bringes.size()<<endl;
    for (int i = 0; i < bringes.size(); i++)
    {
        cout<<bringes[i].first<<" "<<bringes[i].second<<endl;
    }
}