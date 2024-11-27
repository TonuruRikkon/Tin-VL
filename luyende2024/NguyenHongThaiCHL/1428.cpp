#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
bool vis[int(1e6)+1];
int steps[int(1e6)+1],from[int(1e6)+1];

void Dijstra(pair<int,int> s)
{

    memset(vis,false,sizeof(vis));
    memset(steps,0,sizeof(steps));
    memset(from,0,sizeof(from));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    vis[s.second]=true;
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=topp.second;
        vis[topp.second]=true;
        q.pop();
        for(auto v:inp[u]){
            if(vis[v.second]==false){
                q.push(v);
                steps[v.second]=steps[u]+v.first;
                from[v.second]=u;
            }
        }
    }
    
}

int main()
{
    freopen("1428.INP","r",stdin);
    freopen("1428.OUT","w",stdout);
    vector<char> bo;
    int p,ans=int(1e9);
    char bonhat=0;
    cin>>p;
    for (int i = 0; i < p; i++)
    {
        char u,v;
        int c;
        cin>>u>>v>>c;
        if(u>='A'&&u<='Y') bo.push_back(u);
        else if(v>='A'&&v<='Y') bo.push_back(v);
        inp[u].push_back({c,v});
        inp[v].push_back({c,u});
    }
    Dijstra({0,'Z'});
    for(char x:bo){
        if(ans>steps[x]){
            ans=steps[x];
            bonhat=x;
        }
    }
    cout<<bonhat<<" "<<ans;
}