#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,k;
    cin>>n>>p>>k;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    sort(inp.begin(),inp.end());
    vector<int> dp(p+1,0);
    for (int i = k-1; i < n; i++)
    {
        int cost=inp[i];
        for (int w = p; w >= cost; w--)
        {
            dp[w]=max(dp[w],dp[w-cost]+k);
        }
    }
    
    for (int i = 0; i < k-1; i++)
    {
        int cost=inp[i];
        for (int w = p; w >= cost; w--)
        {
            dp[w]=max(dp[w],dp[w-cost]+1);
        }
        
    }
    
    cout<<dp[p];
}