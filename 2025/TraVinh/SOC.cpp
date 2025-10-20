#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> inp;
    vector<int> dp(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int pos=min(k,i);
        dp[i]=dp[i-1]+inp[i-1];
        for (int j = pos; j > 0; j--)
        {
            dp[i]=max(dp[i-j]+inp[i-1],dp[i]);
        }
        
    }
    cout<<dp[n];


}