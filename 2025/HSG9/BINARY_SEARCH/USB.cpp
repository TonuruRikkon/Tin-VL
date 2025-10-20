#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> inp;
    vector<int> dp(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        dp[i+1]=dp[i]+x;
    }
    int ans=upper_bound(dp.begin(),dp.end(),x)-dp.begin();
    cout<<ans-1;
}