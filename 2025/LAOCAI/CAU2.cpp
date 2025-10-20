#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<char,int> mp;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin>>x;
        mp[x]++;
    }
    long long ans=0;
    for(auto x:mp){
        ans+=x.second*(x.second-1)/2;
    }
    cout<<ans;
}