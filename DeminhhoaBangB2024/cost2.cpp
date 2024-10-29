#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj(int(1e6));

void dfs(int s,vector<int>& t,vector<int>& cnt,vector<int>& d,int cha)
{
    cnt[s]=t[s];
    for(auto x:adj[s]){
        if(x.first!=cha){
            dfs(x.first,t,cnt,d,s);
            cnt[s]+=cnt[x.first];
            d[s] += d[x.first] + (long long)cnt[x.first] * x.second;
        }
    }
}

void dfs2(int s, vector<int>& t, vector<int>& cnt, vector<int>& d, int cha)
{
    for(auto x:adj[s]){
        if(x.first!=cha){
            d[x.first] = d[s] - cnt[x.first]*x.second + (cnt[1]-cnt[x.first])*x.second;
            dfs2(x.first, t, cnt, d, s);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> t(n+1),cnt(n+1),d(n+1);
    fill(cnt.begin(),cnt.end(),0);
    fill(d.begin(),d.end(), 0);
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
    dfs(1,t,cnt,d,-1);
    dfs2(1,t,cnt,d,-1);
    long long minn=*min_element(d.begin()+1,d.end());
    cout<<minn<<" ";
    long long maxx=*max_element(d.begin()+1,d.end());
    cout<<maxx<<" ";
    if(k>maxx){
        cout<<"GOOD";
    }
    else if(k<minn){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}
