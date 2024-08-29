#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[1000],count0=0,count1=0,minn,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==0) count0++;
        else if(a[i]==1) count1++;
    }
    if(min(count0,count1)==count0) minn=0;
    else minn=1;
    for (int i = 1; i < n; i++)
    {
        if(a[i]!=minn){
            if(a[i]!=a[i-1]) ans++;
        }
    }
    cout<<ans;
}