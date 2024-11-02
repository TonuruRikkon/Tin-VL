#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,ans=0;
    cin>>n;long d[5];memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        long a;cin>>a;
        d[a]++;
    }
    if(d[2]%2==0) ans+=d[2]/2+d[4];
    else ans+=d[2]/2+1+d[4];
    if(d[3]>d[1]) ans+=d[3];
    else ans+=d[1];
    cout<<ans;
}
