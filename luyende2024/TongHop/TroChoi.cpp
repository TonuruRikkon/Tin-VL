#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> mp;
    int n,max=0,ans;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second>=max){
            max=x.second;
            ans=x.first;
        }
    }
    cout<<ans;
}