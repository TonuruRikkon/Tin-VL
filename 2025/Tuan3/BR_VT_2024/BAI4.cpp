#include <bits/stdc++.h>
using namespace std;

int knapsack(int &n, int &k, vector<int> &w, vector<int> &v){
    vector<int> dp(k+1,0);
    for (int i = 0; i < n; i++)
    {
        for (int wi = w[i]; wi <= k; wi++)
        {
            dp[wi]=max(dp[wi],dp[wi-w[i]]+v[i]);
        }
    }
    return dp[k];
}

int main()
{
    int n,K;
    cin>>n>>K;
    int k=K*1024;
    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<knapsack(n,k,w,v);    
}