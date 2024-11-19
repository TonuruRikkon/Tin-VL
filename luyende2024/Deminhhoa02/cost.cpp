#include <bits/stdc++.h>
using namespace std;

int cnt[int(1e6)+1],ans[int(1e6)+1];

vector<pair<int,int>> inp[int(1e6)];

void dfs(int s,vector<int>& t,int father)
{
    int u=s;
    cnt[u]=t[u];
    for(auto v:inp[u]){
        if(v.first!=father){
            dfs(v.first,t,u);
            cnt[u]+=cnt[v.first];
            ans[u]+= ans[v.first]+(cnt[v.first]*v.second);
        }
    }
}

void dfs2(int s,vector<int>& t,int father)
{
    int u=s;
    for(auto v:inp[u]){
        if(v.first!=father){
            ans[v.first]= ans[u]-(cnt[v.first]*v.second)+((cnt[1]-cnt[v.first])*v.second);
            dfs(v.first,t,u);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> t;
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        inp[x].push_back({y,w});
        inp[y].push_back({x,w});
    }
    t.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        t.push_back(x);
    }
    dfs(1,t,-1);
    dfs2(1,t,-1);
    int minn=*min_element(ans+1,ans+n),maxx=*max_element(ans+1,ans+n);
    cout<<minn<<" "<<maxx<<" ";
    if(minn>k){
        cout<<"NO";
    }
    else if(minn<=k&&maxx>=k){
        cout<<"YES";
    }
    else if(maxx>k){
        cout<<"GOOD";
    }

}