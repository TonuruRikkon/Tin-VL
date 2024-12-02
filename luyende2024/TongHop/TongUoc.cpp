#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,ans=0;
    cin>>a>>b;
    if(b%3!=0){
        cout<<0;
        return 0;
    }
    long long p=__gcd(a,(b/3));
    for (int i = 1; i*i <= p; i++)
    {
        if(p%i==0){
            if(p/i==i) ans+=i;
            else ans+=i+p/i;
        } 
    }
    cout<<ans;
}