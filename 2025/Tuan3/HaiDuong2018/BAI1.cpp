#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    scanf("%d",&n);
    double ans=0;
    for (int i = 1; i <= n; i++)
    {
        if(i<=5) ans+=6500;
        else if(i<=15) ans+=7800;
        else if(i<=25) ans+=9200;
        else ans+=10300;
    }
    double VAT=ans*0.12;
    cout<<setprecision(2)<<fixed<<ans<<'\n'<<VAT<<'\n'<<ans+VAT;

}