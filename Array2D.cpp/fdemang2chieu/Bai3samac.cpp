#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,i,j;
    cin>>n>>m;
    int a[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
    }
    int b[n][m];
    b[1][1]=a[1][1];
    for (int i=2; i<=n; i++){
        b[i][1]=a[i][1]+b[i-1][1];
        b[1][i]=a[1][i]+b[1][i-1];
    }
    for (int i=2; i<=m; i++){
        b[1][i]=a[1][i]+b[1][i-1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            b[i][j]=a[i][j]+max(b[i-1][j],b[i][j-1]);
        }

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<<"["<<b[i][j]<<"]";
        }
        cout<<endl;
    }
    
    i=n;
    j=m;
    int ii[100],jj[100],k=0;
    while (i>1||j>1)
    {
        ii[k]=i;
        jj[k]=j;
        if(b[i][j]==a[i][j]+b[i-1][j]) i--;
        else j--;
        k++;
    }
cout<<"1 1"<<endl;
    for(int i=k-1;i>=0;i--){
        cout<<ii[i]<<" "<<jj[i]<<endl;
    }
}
