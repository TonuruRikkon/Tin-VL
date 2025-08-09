#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    int n,max=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]>max) max=mp[x];
    }
    cout<<max;
}