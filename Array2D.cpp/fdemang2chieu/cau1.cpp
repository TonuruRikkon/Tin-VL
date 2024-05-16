#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[n][n];
    cin>>n;
    for(int i=1; i<=n;i++){
        a[1][i]=i;
        a[i][1]=i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i][1]*a[1][j]<=2*n) a[i][j]=a[i][1]*a[1][j];
            else a[i][j]=
        }
        
    }
    
}