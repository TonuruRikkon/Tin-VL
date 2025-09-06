#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,long long> mp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string x;
        long long y,z;
        cin>>x>>y>>z;
        mp[x]+=y*z;
    }
    string ans;
    cin>>ans;
    cout<<mp[ans];
}