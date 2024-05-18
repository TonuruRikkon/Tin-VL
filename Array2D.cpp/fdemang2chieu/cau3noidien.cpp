#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100][100],x=0,s=0,check=0,line;
    cin>>n;
    int b[n+1];
    memset(b,0,sizeof(b)+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        line=0;
        x=0;
        for (int j = 1; j <= n; j++)
        {
            if(x==0) x=a[i][j];
            if(a[i][j]<x&&a[i][j]!=0) {
                x=a[i][j];
            }
        }
        s+=x;
        if(x==0) check=1;
    }
    if(check==0&&s!=0) cout<<"Tong do dai:"<<s;
    else cout<<"khong thuc hien duoc";
    
    
}