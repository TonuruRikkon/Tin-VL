#include <bits/stdc++.h>
using namespace std;

long long MOD=1e9+7;

int main()
{
    long long n,k,p;
    cin>>n>>k>>p;
    vector<long long> inp(n),tol(n+1,0);
    for (long long i = 0; i < n; i++)
    {
        cin>>inp[i];
        tol[i+1]=tol[i]+inp[i];
    }
    long long start=p%n;
    long long loop=k/n;
    long long rem=(k+start-1)%n;
    long long ans=(tol[n]-tol[start-1])%MOD;
    ans+=((loop%MOD)*(tol[n]%MOD))%MOD-(tol[n]-tol[start-1])%MOD;
    ans+=tol[rem]%MOD;
    cout<<ans;
}