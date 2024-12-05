#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("TURNO.INP","r",stdin);
    freopen("TURNO.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=5)
        {
            ans+=0*300000;
        }
        else if(a[i]>5 && a[i]<=10)
        {
            ans+=0.2*300000;
        }
        else if(a[i]>10 && a[i]<=15)
        {
            ans+=0.5*300000;
        }
        else if(a[i]>=60)
        {
            ans+=0.8*300000;
        }
        else
        {
            ans+=300000;
        }
    }
    cout<<ans<<"\n";
}
