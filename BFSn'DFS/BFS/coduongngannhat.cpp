#include <bits/stdc++.h>
using namespace std;

const int N=200;
int n,m,S,E;
bool visited[N+1];
int roadto[N+1],trace[N+1];
vector<int> adj[N+1],moved;

void bfs(int S)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(S);
    visited[S]=true;
    while(!q.empty())
    {
        int u = q.front();
        for(int x:adj[u]){
            if(!visited[x]){
                q.push(x);
                visited[x]=1;
                roadto[x]=roadto[u]+1;
                trace[x]=u;
                visited[x]=1;
            }
        }
        q.pop();
    }
}

void find_way(int T)
{
    int x=T;
    while (true)
    {
        moved.push_back(x);
        if(x==S){
            break;
        }
        x = trace[x];
    }
    for (int i = moved.size()-1; i >= 0; i--)
    {
        cout<<moved[i]<<" ";
    }
    
}

int main()
{
    cin>>n>>m>>S>>E;
    memset(roadto,-1,sizeof(roadto));
    for (int i = 0; i < m; i++)
    {
        int inp1,inp2;
        cin>>inp1>>inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    bfs(S);
    cout<<adj[E]<<endl;
    if(adj[E]==-1) return 0;
    find_way(E);
    
}