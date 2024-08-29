#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100],d=0,ans=0;
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = n-1; i > 0; i--)
    {
        if(a[i]<=a[i-1]) {
            ans+=a[i-1]-a[i]+1;
            a[i-1]-=a[i-1]-a[i]+1;
        }
    }
    cout<<ans;
}