#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    map<long long,int> inp;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        inp[x]++;
    }
    for(auto x:inp){
        if(x.second%2!=0) ans++;
    }
    cout<<ans;
}