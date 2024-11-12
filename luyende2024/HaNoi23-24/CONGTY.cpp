#include <bits/stdc++.h>
using namespace std;

vector<int> p[2*int(1e5)+1];
int d=0;

void bfs(int s,vector<bool>& visited,vector<int> a)
{
    visited.resize(sizeof(visited),false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    int u=s;
    while (q.empty()==false)
    {
        for(int v:p[s]){
            if(visited[v]==false){
                q.push(v);
                visited[v]=true;
                if(a[v-1]<a[u-1]) d++;
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
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        d=0;
        bfs(x,visited,a);
        cout<<d;
    }
    
}