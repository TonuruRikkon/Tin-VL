#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp(26,0);
    for (int i = 0; i < 26; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    string s;
    cin>>s;
    vector<int> dp(s.size()+1,0);
    for (int i = 1; i <= s.size(); i++)
    {
        dp[i]=dp[i-1]+inp[s[i-1]-'a'];
    }
    
    cout<<ans;
}