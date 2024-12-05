#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TURNO.INP","r",stdin);
    freopen("TURNO.OUT","w",stdout);
    int n,ans=0,t=300000;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x<=5) ans+=0;
        else if(x<=10) ans+=240000;
        else if(x<=15) ans+=150000;
        else if(x<60) ans+=t;
        else ans+=60000;
    }
    cout<<ans;
}
