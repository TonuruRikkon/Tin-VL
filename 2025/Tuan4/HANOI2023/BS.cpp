#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x;
    cin>>n>>x;
    int ans=0;
    for (long long i = 1; i <= n; i++)
    {
        if(x/i<=n&&x%i==0) ans++;
    }
    cout<<ans;
}