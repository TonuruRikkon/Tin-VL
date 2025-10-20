#include <bits/stdc++.h>
using namespace std;

void bfs(int inp, vector<bool> &visit, vector<vector<int>> adj ,vector<int> &trace, vector<int> &step)
{
    queue<int> q;
    q.push(inp);
    visit[inp]=true;
    step[inp]=0;
    while(q.empty()==false){
        int u=q.front();
        for(int x:adj[u]){
            if(visit[x]==false){
                trace[x]=u;
                step[x]=step[u]+1;
                visit[x]=true;
                q.push(x);
            }
        }
        q.pop();
    }
}

int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<int>> inp(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    vector<bool> visit(n+1,0);
    vector<int> trace(n+1,-1);
    vector<int> ans(n+1,0);
    bfs(s,visit,inp,trace,ans);
    if(trace[t]!=-1){
        cout<<ans[t]<<'\n';
        vector<int> outtrace;
        int outp=t;
        outtrace.push_back(outp);
        while(outp!=s)
        {
            outp=trace[outp];
            outtrace.push_back(outp);
        }
        reverse(outtrace.begin(),outtrace.end());
        for(int x:outtrace){
            cout<<x<<' ';
        }
    }
    else cout<<-1;
}