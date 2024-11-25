#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
bool visited[int(1e6)];
int cost[int(1e6)+1];

int prim(pair<int,int> s,int k,vector<bool> tram)
{
    int moved=0,diem=0;
    memset(visited,false,sizeof(visited));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(s);
    visited[s.second]=true;
    while (q.empty()==false)
    {
        moved+=q.top().first;
        if(tram[q.top().second]==true) diem++;
        if(diem==k) return moved;
        int u=q.top().second;
        visited[u]=true;
        q.pop();
        for(auto v:inp[u]){
            if(visited[v.second]==false){
                q.push(v);
            }
        }
    }
    return moved;
}

int main()
{
    int n,m,k,tr,min_tr=1e6;
    cin>>n>>m>>k;
    vector<bool> tram(n+1,false);
    for (int i = 0; i < k; i++)
    {
        cin>>tr;
        tram[tr]=true;
    }
    for (int i = 0; i < m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        if(x==tr||y==tr) min_tr=min(min_tr,c);
        inp[x].push_back({c,y});
        inp[y].push_back({c,x});
    }
    cout<<prim({0,tr},k,tram);
}