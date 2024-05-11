#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],s=0,b[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            s+=a[i][j];
            if(i==1) b[j]=a[i][j];
        }
    }
    int x=a[0][0],y=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j]%3==0){
                y=a[i][j];
                break;
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(x<a[i][j]) x=a[i][j];
            if(a[i][j]%3==0&&a[i][j]<y) y=a[i][j];
        }
        
    }
    
    sort(b,b+m,greater<int>());
    for(int i=0;i<m;i++){
        a[1][i]=b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<"["<<a[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<"Tong cac phan tu:"<<s<<endl<<"GTLN:"<<x<<endl;
    if(y!=0) cout<<"GTNN chia het cho 3:"<<y;
    else if(y==0) cout<<"Khong co gia tri chia het cho 3.";
}