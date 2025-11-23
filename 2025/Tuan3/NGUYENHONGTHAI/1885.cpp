#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string inp;
    cin>>inp;
    vector<int> tol(n+1,0);
    unordered_map<int,long long> cnt;
    cnt[0]=1;
    for (int i = 0; i < n; i++)
    {
        if(inp[i]=='a'){
            tol[i+1]=tol[i]+1;
        }
        else tol[i+1]=tol[i]-1;
    }
    long long ans=0;
    for (int i = 1; i <= n; i++)
    {
        ans+=cnt[tol[i]];
        cnt[tol[i]]++;
    }
    cout<<ans;
    
}