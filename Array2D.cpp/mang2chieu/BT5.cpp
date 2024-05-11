#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,check,d=0;
    cin>>n>>m;
    int a[n][m],b[n*m];
    memset(b,0,n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 2; k < a[i][j]; k++)
            {
                if(a[i][j]%k==0) {
                    check=0;
                    break;
                }
                else check=1; 
            }
            if(check==1){
                b[d]=a[i][j];
                d++;
                check=0;
            }
        }
    }
    for (int i = 0; i < d; i++)
    {
        cout<<"["<<b[i]<<"]";
    }
    cout<<endl<<"So luong so nguyen to la:"<<d;
    
}