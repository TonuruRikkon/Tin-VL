#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(1e6)+1];
bool visited[int(1e6)+1];
int steps[int(1e6)+1],from[int(1e6)+1];

void bfs(int s)
{
    memset(visited, false,sizeof(visited));
    queue<int> q;
    visited[s]=true;
    q.push(s);
    steps[s]=0;from[s]=-1;
    while (q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int v:inp[u]){
            if(visited[v]==false){
                steps[v]=steps[u]+1;
                from[v]=u;
                q.push(v);
                visited[v]=true;
            }
        }
    }
    
}

int main()
{
    int n,m,s,t;
    vector<int> ans;
    cin>>n>>m>>s>>t;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    memset(steps,0,sizeof(steps));
    bfs(s);
    cout<<steps[t]<<endl;
    int way=t;
    while(way!=s){
        ans.emplace(ans.begin(),way);
        way=from[way];
    }
    ans.emplace(ans.begin(),way);
    for(int x:ans) cout<<x<<" ";
}