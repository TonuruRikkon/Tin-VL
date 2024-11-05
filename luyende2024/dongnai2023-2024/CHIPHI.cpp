#include <bits/stdc++.h>
using namespace std;

int d[int(1e6)];

void demuoc()
{
    memset(d,0,sizeof(d));
    for (int i = 2; i < int(1e6); i++)
    {
        for (int j = i; j < int(1e6); j+=i)
        {
            d[j]++;
        }
        
    }
    
}

int main()
{
    freopen("CHIPHI.INP","r",stdin);
    freopen("CHIPHI.OUT","w",stdout);
    int t;
    cin>>t;
    demuoc();
    for (int i = 0; i < t; i++)
    {
        int n,m,ans=0;
        cin>>n>>m;
        int a[n+1][m+1],b[n+1][m+1];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin>>x;
                a[i][j]=d[x];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                b[i][j]=a[i][j]+min(b[i-1][j],b[i][j-1]);
            }
        }
        cout<<b[n][m];
    }
    
}