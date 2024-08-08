#include <bits/stdc++.h>
using namespace std;

int a[int(1e6)+1],d[int(1e6)+1];


void tonguoc(){memset(a,0,sizeof(a));memset(d,0,sizeof(d));
    for (int i = 0; i <= 1e6; i++)
    {
        for (int j = i; j <= 1e6; j+=i)
        {
            a[j]+=i;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    tonguoc();

    for (int i = 1; i <= 1e6; i++)
    {
        if(a[i]%2==0) d[i]=d[i-1]+1;
        else d[i]=d[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        int x,y,ans=0;
        cin>>x>>y;
        cout<<d[y]-d[x-1]<<endl;
    }
}