#include<bits/stdc++.h>
using namespace std;

vector<int> tso(int(1e6)+1,0),inp[int(1e6)+1];
int ans=0;

void dfs(int s, int father, int minn,int d){
    int u=s;
    for(int v:inp[u]){
        if(v!=father){
            int minn2=min(tso[v],minn);
            int d2=d+1;
            ans=max(ans,d2*minn2);
            dfs(v,u,minn2,d2);            
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>tso[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i,-1,tso[i],0);
    }
    cout<<ans;
}