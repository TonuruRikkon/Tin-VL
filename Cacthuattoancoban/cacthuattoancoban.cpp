#include <bits/stdc++.h>
using namespace std;

main()
{
    int n,k,ans=0,x;
    cin>>n>>k;
    int a[n+1],s[n+1];
    memset(s,0,sizeof(s));
    for (int i = 1; i <= n; i++)    
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        x=lower_bound(s,s+1+n,s[i]+k)-s;
        if(x<=n) ans+= n-x+1;
    }
    cout<<ans;
}