#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<pair<int,int>>> adj;

void dfs(int s,vector<int>& t,vector<int>& ans,int& tol)
{
    int d=t[s];
    visited[s]=true;
    for(auto x:adj[s]){
        if(visited[x.first]==false){
            tol+=(d*x.second);
            d+=t[x.first];
            dfs(x.first,t,ans,tol);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    adj.resize(n+1);
    visited.resize(n+1,false);
    vector<int> t(n+1),ans;
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int tol=0;
        fill(visited.begin(),visited.end(),false);
        dfs(i,t,ans,tol);
        ans.push_back(tol);
    }
    
    for(int x:ans) cout<<x<<" ";
    cout<<endl;

    int maxx=*max_element(ans.begin(),ans.end()),minn=*min_element(ans.begin(),ans.end());
    cout<<maxx<<" "<<minn<<" ";
    if(k>maxx){
        cout<<"YES";
    }
    else if(k<minn){
        cout<<"NO";
    }
    else{
        cout<<"OK";
    }
}
