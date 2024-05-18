#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100][100],k=0;
    for (int i = 1; i <= n; i++)
    {
        k=2;
        for (int j = 1; j <= n; j++)
        {
            if(i*j<=2*n) a[i][j]=i*j;
            else{
                a[i][j]=k;
                k+=2;
            }
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}