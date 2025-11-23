#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> knapsack(vector<int> &w, vector<int> &v, int W)
{
    int n=w.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int pick=0;
            if(w[i-1]<=j){
                pick=v[i-1]+dp[i-1][j-w[i-1]];
            }
            dp[i][j]=max(dp[i-1][j],pick);
        }
        
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("GOLD.INP","r",stdin);
    // freopen("GOLD.OUT","w", stdout);
    int n,W,T;
    cin>>n>>W>>T;
    vector<int> w;
    vector<int> t;
    vector<int> v(n+1,0),vw,vt;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        if(v[i]<T){
            w.push_back(x);
            vw.push_back(v[i]);
        }
        else{
            t.push_back(x);
            vt.push_back(v[i]);
        }
    }
    vector<vector<int>> dp=knapsack(w,vw,W);
    int sz=w.size();
    int szt=t.size();
    int ans=dp[sz][W];
    for (int i=0; i<szt;i++)
    {
        ans=max(ans,dp[sz][W-t[i]]+vt[i]);
    }
    cout<<ans;
}