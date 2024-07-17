#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,ans=0,k,l;
    cin>>n>>x>>y;
    int a[n+1],s[n+1];
    memset(s,0,sizeof(s));
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        k=upper_bound(s,s+1+n,s[i]+x)-s;
        l=upper_bound(s,s+1+n,s[i]+y)-s;
        if(k<=n&&l<=n) ans+=l-k;
        else if(k<=n) ans+=l-1-k;
        cout<<i<<":"<<k<<":"<<l<<":"<<ans<<endl;
    }
    cout<<ans;
}
