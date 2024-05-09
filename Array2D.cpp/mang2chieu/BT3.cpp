#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Nhap kich thuong mang:";
    int n,m;
    cin>>n>>m;
    cout<<"Nhap mang 1:"<<endl;
    double a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"Nhap mang 2:"<<endl;
    double b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>b[i][j];
        } 
    }
    for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++)
    {
        cout<<"["<<a[i][j]+b[i][j]<<"]";
    }
    cout<<endl;
    }
}