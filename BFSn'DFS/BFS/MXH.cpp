#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> adj;
set<string> visited,ans;
void bfs(string s)
{
    queue<string> q;
    q.push(s);
    visited.insert(s);
    while (!q.empty())
    {
        string checking=q.front();
        for(string x:adj.at(checking)){
            if(visited.count(x)==1) continue;
            q.push(x);
            visited.insert(x);
            if(checking!=s) {
                ans.insert(x);
            }
        }
        q.pop();
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        string x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs("A");
    for(string x:ans){
        cout<<x<<' ';
    }
}