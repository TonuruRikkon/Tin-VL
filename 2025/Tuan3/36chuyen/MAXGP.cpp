#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> inp(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>inp[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> ans(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        dp[i][1]=1;
    }
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(inp[i]%q==0){
                int uoctrc=inp[i]/q;
                for (int p = 1; p < i; p++)
                {
                    if(inp[p]==uoctrc){
                        dp[i][j]+=dp[p][j-1];
                    }
                }
                
            }
        }

        long long tol=0;
        for (int i = 1; i <= n; i++)
        {
            tol+=dp[i][j];
        }
        ans[j]=tol;
    }
    for (int i = 2; i <= n; i++)
    {
        cout<<ans[i]<<' ';
    }
    
    

}