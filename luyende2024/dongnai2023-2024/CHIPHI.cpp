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
    int t;
    cin>>t;
    demuoc();
    for (int i = 0; i < t; i++)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        memset(a,0,sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin>>x;
                a[i][j]=d[x];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                a[i][j]=a[i-1][j-1]+min(a[i-1][j],a[i][j-1]);
            }
            
        }
        
        
    }
    
}