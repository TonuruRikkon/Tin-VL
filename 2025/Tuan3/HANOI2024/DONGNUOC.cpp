#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DONGNUOC.INP", "r", stdin);
    freopen("DONGNUOC.OUT", "w", stdout);
    long long n;
    cin>>n;
    long long ans=n/5;
    ans+=n%5/3+n%5%3/2;
    if(n%5%3==1) ans++;
    cout<<ans;
}