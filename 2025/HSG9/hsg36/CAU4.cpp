#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n,k;
    cin>>n>>m>>k;
    vector<vector<int>> inp(n+1,vector<int>(m+1,0));
    for (int i = 0; i < k; i++)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        for (int j = x; j <= u; j++)
        {
            for (int l = y; l <= v; l++)
            {
                inp[j][l]++;
            }
            
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    int ans=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1 && j > 1 &&
                inp[i][j] == inp[i-1][j] &&
                inp[i][j] == inp[i][j-1] &&
                inp[i][j] == inp[i-1][j-1]) {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    // for(auto x:dp){
    //     for(int y:x) cout<<y<<' ';
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';
    
}