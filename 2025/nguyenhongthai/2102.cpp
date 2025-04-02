#include <bits/stdc++.h>
using namespace std;

int count(string s)
{
    int n =s.size();
    vector<vector<int>> dp(n, vector<int>(n, int(1e9)));
    
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int  i = 0; i <= n-len; i++)
        {
            int j = i + len - 1;
            string sub = s.substr(i, len);
            dp[i][j] = len;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }

            for(int k=1;k <= len/2; k++){
                if(len%k==0){
                    string pattern = sub.substr(0, k);
                    bool isPattern = true;
                    for(int l = 0; l < len; l+=k){
                        if(sub.substr(l, k) != pattern){
                            isPattern = false;
                            break;
                        }
                    }
                    if(isPattern){
                        dp[i][j] = min(dp[i][j], int(dp[i][i + k - 1] + 2 + to_string(len / k).size()));
                    }
                }
            }
            
        }
        
    }
    return dp[0][n-1];
}

int main()
{
    while(true){
        string inp;
        cin>>inp;
        if(inp=="*"){
            break;
        }
        cout<<count(inp)<<endl;
    }
    return 0;
}