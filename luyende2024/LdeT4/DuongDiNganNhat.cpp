#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
bool visited[int(1e6)+1];
int cost[int(1e6)+1];

void bfs(int s)
{
    memset(visited,false,sizeof(visited));
    memset(cost,0,sizeof(cost));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while (q.empty()==false)
    { 
        int u=q.front();
        q.pop();
        for(auto v:inp[u]){
            if(visited[v.first]==false){
                visited[v.first]=true;
                q.push(v.first);
                int pos=v.first,w=v.second;
                if(cost[pos]>(cost[u]+w)||cost[pos]==0){
                    cost[v.first]=cost[u]+v.second;
                }
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
        int u,v,w;
        cin>>u>>v>>w;
        inp[u].push_back({v,w});
        inp[v].push_back({u,w});
    }
    int start,endd;
    cin>>start>>endd;
    bfs(start);
    cout<<cost[endd];
}