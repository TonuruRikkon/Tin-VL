#include <bits/stdc++.h>
using namespace std;

bool visited[int(1e6)+1];
vector<int> inp[int(1e6)+1];
string ans;

void dfs(int s)
{
    int u=s;
    ans.push_back(char(u+'0'));ans.push_back(' ');
    visited[u]=true;
    for(int v:inp[u]){
        if(visited[v]==false){
            dfs(v);
        }
    }
}

int main()
{
    memset(visited,false,sizeof(visited));
    int n,m;
    cin>>n>>m;
    vector<string> outp;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]==false){
            ans="";
            dfs(i);
            outp.push_back(ans);            
        }
    }
    for(string x:outp){
        cout<<x<<endl;
    }
}