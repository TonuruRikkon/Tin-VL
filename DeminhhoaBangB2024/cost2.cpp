#include <bits/stdc++.h>
using namespace std;

bool visited[int(1e6)];
vector<vector<int,int>> adj(int(1e6));

void dfs(int s,vector<int> t,vector<int>ans)
{
    memset(visited,false,sizeof(visited));
    int d=t[s-1],tol=0;
    visited[s]=true;
    for(auto x:adj[s]){
        if(visited[x.first]==false){
            tol+=(d*x.second)
            d+=t[x.first-1];
            dfs(x.second);
        }
    }
    ans.push_back(tol);
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> t;
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        t.push_back(x);
    }
    cout<<*max_elemet(adj.begin(),adj.end())<<" "<<*min_element(adj.begin(),adj.end())<<" ";
    if(k>*max_elemet(adj.begin(),adj.end())){
        cout<<"YES";
    }
    else if(k<*min_element(adj.begin(),adj.end())){
        cout<<"NO"
    }
    else{
        cout<<"OK"
    }
}
