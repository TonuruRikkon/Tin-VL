#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("GCDAB.INP", "r", stdin);
    freopen("GCDAB.OUT", "w", stdout);
    long long n;
    cin>>n;
    unsigned long long ans=0;
    for (long long b = 1; b <= n;)
    {
        long long temp=n/b;
        long long end=n/temp;
        end=min(n,end);
        ans+=(long long)(end-b+1)*temp;
        b=end+1;
    }
    cout<<ans;

}