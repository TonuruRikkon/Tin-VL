#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,k,used=0,size=0;
    cin>>m>>n;
    cin>>k;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
        
    }
    int b[m+1][n+1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i-1][j-1];
        }
        
    }
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
                cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<size;
}