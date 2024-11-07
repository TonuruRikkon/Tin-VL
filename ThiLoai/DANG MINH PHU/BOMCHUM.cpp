#include <bits/stdc++.h>
using namespace std;

int demuoc(long long x){
    long long ans=0;
    for (int i = 1; i*i <= x; i++)
    {
        if(x%i==0) ans+=i+x/i;
        if(i==x/i) ans-=i;
    }
    return ans;
}

int main()
{
    freopen("BOMCHUM.INP","r",stdin);
    freopen("BOMCHUM.OUT","w",stdout);
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        long long x;
        cin>>x;
        cout<<demuoc(x)<<" ";
    }
    
}