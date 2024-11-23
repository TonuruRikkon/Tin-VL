#include <bits/stdc++.h>
using namespace std;

int uoc(int s)
{
    int ans=0;
    for (int i = 2; i*i <= s; i++)
    {
        if(s%i==0){
            if(s/i==i) ans++;
            else ans+=2;
        }
    }
    return ans;
}

int main()
{
    long long n,k,ans=0;
    cin>>n>>k;
    if(k<=n&&k!=1) ans+=2;
    if(k==1) cout<<1;
    else if(n*n>=k){
        if(k!=sqrt(k)*sqrt(k)) ans+=uoc(k);
        else if(k==sqrt(k)*sqrt(k)) ans++;
        cout<<ans;
    }
    else cout<<0;
}