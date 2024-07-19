#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,i,j;
    cin>>n;
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }
    int b[n+1][n+1];
    b[1][1]=a[1][1];
    for (int i=2; i<=n; i++){
        b[i][1]=a[i][1]+b[i-1][1];
        b[1][i]=a[1][i]+b[1][i-1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            b[i][j]=a[i][j]+min(b[i-1][j],b[i][j-1]);
        }

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<"["<<b[i][j]<<"]";
        }
        cout<<endl;
    }
    
    i=n;
    j=n;
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
