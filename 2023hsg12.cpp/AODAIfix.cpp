#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    int a[n+1],d[4+1];
    memset(d,0,4+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        d[a[i]]++;
    }
    ans+=d[4];
    ans+=d[3]; if(d[1]>d[3]) d[1]=d[1]-d[3];else d[1]=0;
    ans+=d[2]/2; if(d[2]%2!=0){
        if(d[1]>2) d[1]=d[1]-2;
        else d[1]=0;
    } 
    ans+=d[1];
    cout<<ans;
}