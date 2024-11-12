#include <bits/stdc++.h>
using namespace std;

vector<int> p[2*int(1e5)+1];
int d[int(1e5)*2];

void bfs(int s,vector<bool>& visited,vector<int> a)
{
    visited.resize(sizeof(visited),false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while (q.empty()==false)
    {
        int u=q.front();
        d[u]=true;
        for(int v:p[u]){
            if(visited[v]==false){
                q.push(v);
                visited[v]=true;
                if(a[v-1]>a[u-1]) d[u]=false;
            }
        }
        q.pop();
    }
    
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> a,u;
    vector<bool> visited(n+1,false);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 1; i <= n-1; i++)
    {
        int x;
        cin>>x;
        p[x].push_back(i+1);
    }
    bool d[n+1];
    for (int i = 0; i < q; i++)
    {
        memset(d,false,sizeof(d));
        int x;
        cin>>x;
        bfs(x,visited,a);
    }
    
}