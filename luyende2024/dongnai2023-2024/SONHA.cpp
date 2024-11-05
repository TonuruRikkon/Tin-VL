#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("SONHA.INP","r",stdin);
    freopen("SONHA.OUT","w",stdout);
    string str;
    cin>>str;
    long long n=atoi(str.c_str()),d=9,ans=0;
    if(str.size()==1) ans+=n*80000;
    else
    for (int i = 1; i <= 9; i++)
    {
        if(str.size()==i){
            ans+=(n-(d/10))*i*80000;
            break;
        }
        else{
            ans+=d*i*80000;
            d=d*10;
        }
    }
    cout<<ans;
}