#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,prev=0,temp=1,ans=0;
    cin>>n;
    int d[n+1],a[n+1];
    for (int i = 0; i <= n; i++)
    {
        d[i]=1;
    }
    d[0]=0;
    a[0]=int(1e10);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]) d[i]=d[i-1]+1 ;
    }
    cout<<*max_element(d+1,d+1+n);
}