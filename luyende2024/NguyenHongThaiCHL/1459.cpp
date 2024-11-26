#include <bits/stdc++.h>
using namespace std;

struct diem
{
    int first,second,third;
};

vector<diem> inp[int(1e7)];
bool vis[int(1e7)];
int chiphi=0,soloai=0;
vector<int> ans;

void prim(diem s)
{
    memset(vis,false,sizeof(vis));
    priority_queue<diem,vector<diem>,greater<diem>> q;
    q.push(s);
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=topp.second;
        chiphi+=topp.first;
        if(vis[u]==true){
            soloai++;
            ans.push_back(topp.third);
        }
        vis[u]=true;
        q.pop();            
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
    prim({0,1,0});
    if(soloai==0) cout<<-1;
    else{
        cout<<chiphi<<" "<<soloai<<endl;
        for(auto x:ans) cout<<x<<endl;
    }
    
}