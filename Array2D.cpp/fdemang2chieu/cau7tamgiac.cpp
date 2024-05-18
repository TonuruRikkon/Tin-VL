#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ii,jj;
    cin>>n;
    int a[n+1][n+1],b[n+1][n+1];
    memset(b,0,sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b[i][j]=a[i][j]+max(b[i-1][j],b[i-1][j-1]);
        }
        
    }
    int ans;
    ans = b[n][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if(b[n][i]>ans) ans = b[n][i];
    }
    
    cout<<ans;
    
    
}