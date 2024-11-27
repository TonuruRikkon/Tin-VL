#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int t,m;
        cin>>t>>m;
        mp[t]=max(mp[t],m);
    }
    for (auto x:mp)
    {
        ans+=x.second;
    }
    cout<<ans;
}