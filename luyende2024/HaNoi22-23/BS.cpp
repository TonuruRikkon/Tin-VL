#include <bits/stdc++.h>
using namespace std;

int uoc(long long s)
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
    int n,x,ans=0;
    cin>>n>>x;
    if(x==1) cout<<1;
    else if(n*n<x) cout<<0;
    else{
        if(x<=n) ans+=2;
        int sqrtx=sqrt(x);
        if(sqrtx*sqrtx==x){
            ans++;
        }
        else if(sqrtx*sqrtx!=x){
            ans+=uoc(x);
        }
    }
    cout<<ans;
}