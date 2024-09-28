#include <bits/stdc++.h>
using namespace std;

int n,m,mid,end;
vector<int> adj[2*int(1e5)],movedto;
int trace[2*int(1e5)+1], steps[2*int(1e5)+1],ans[2*int(1e5)];
bool visited[2*int(1e5)+1];

void bdf(int s)
{
    memset(visited,false, sizeof(visited));
    memset(steps,-1,sizeof(steps));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    steps[s]=0;
    while (!q.empty())
    {
        int checking=q.front();
        for(int x:adj[checking]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
                steps[x]=steps[checking]+1;
            }
        }
        q.pop();
    }
    
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bdf(1);
    for (int i = 1; i <= n; i++)
    {
        ans[i]=steps[i];
    }
    bdf(n);
    for (int i = 1; i <= n; i++)
    {
        if(steps[i]!=-1)
        ans[i]+=steps[i];
    }
    for(int i=1; i<=n;i++){
        cout<<ans[i]<<' ';
    }
}