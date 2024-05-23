#include <bits/stdc++.h>
using namespace std;

int main()
{
    int long long n,ref,max;
    cin>>n;
    int long long a[n+1],d[100000],ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    max=a[1];
    for (int i = 1; i <= n; i++)
    {
        if(max<a[i])max=a[i];
    }
    
    for (int i = 1; i<= n; i++)
    {
        d[a[i]]++;
    }
    for (int i = 1; i <= max+1; i++)
    {
        ans+=(d[i]*(d[i]-1))/2;
    }
    cout<<ans;
    
    
}