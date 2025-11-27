#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> inp(n);
    vector<vector<int>> dp(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(inp[j]<inp[i]) dp[i][j]=dp[i][j-1]+1;
            else dp[i][j]=dp[i][j-1];
            // cout<<dp[i][j]<<' ';
        }
        // cout<<'\n';
    }
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        long long ans=0;
        for (int f = l-1; f <= r-1; f++)
        {
            for (int s = f+1; s <= r-1; s++)
            {
                if(inp[f]>inp[s]) ans++;
            }
            
        }
        cout<<ans<<'\n';
        
    }
    
    
}