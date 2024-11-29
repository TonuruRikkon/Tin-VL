#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
vector<int> cost(int(1e6)+1,int(1e9));

struct guard{
    int bg,end;
};



void dijkstra(pair<int,int> s)
{
    fill(cost.begin(),cost.end(),int(1e9));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    cost[s.second]=0;
    while (q.empty()==false)
    {
        auto topp=q.top();
        int u=topp.second;
        q.pop();
        for(auto v:inp[u]){
            
            if(cost[v.second]>cost[u]+v.first){
                cost[v.second]=cost[u]+v.first;
                q.push({cost[v.second],v.second});
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
    }
    dijkstra({0,0});
    cout<<cost[n];
}