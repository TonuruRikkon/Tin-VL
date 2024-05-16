#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    int b[n][n];
    b[0][0]=a[0][0];
    for (int i=1; i<n; i++){
        b[i][0]=a[i][0]+b[i-1][0];
        b[0][i]=a[0][i]+b[0][i-1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            b[i][j]=a[i][j]+min(b[i-1][j],b[i][j-1]);
        }
        
    }
    int ii[n],jj[n],i=n-1,j=n-1,k=0;
    while (i>0||j>0)
    {
        ii[k]=i;
        jj[k]=j;
        if(b[i][j]==a[i][j]+b[i-1][j])i--;
        else j--;
    }
    i=n;
    j=n;
    int ii[100],jj[100],k=0;
    while (i>0||j>0)
    {
        ii[k]=i;
        jj[k]=j;
        if(b[i][j]==a[i][j]+b[i-1][j]) i--;
        else j--;
        k--;
    }
    
    
    
    
    
}