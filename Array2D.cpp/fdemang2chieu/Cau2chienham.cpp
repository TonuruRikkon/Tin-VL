#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a[100][100],k=0;
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i][j]==1&&a[i-1][j]==0&&a[i][j-1]==0&&a[i-1][j-1]==0) k++;
        }
        
    }
    cout<<k;
    
}