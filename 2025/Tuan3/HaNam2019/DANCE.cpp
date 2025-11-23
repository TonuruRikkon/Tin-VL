#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DANCE.INP", "r", stdin);
    freopen("DANCE.OUT", "w", stdout);
    int n;
    cin>>n;
    string inp;
    cin>>inp;
    vector<long long> tol(n+1,0); 
    map<long long,long long> cnt;
    cnt[0]=1;
    long long ans=0;
    for (int i = 0; i < n; i++)
    {
        if(inp[i]=='a') tol[i+1]=tol[i]+1;
        else tol[i+1]=tol[i]-1;
        ans+=cnt[tol[i+1]]++;
    }
    cout<<ans;
}