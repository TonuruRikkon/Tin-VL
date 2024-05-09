#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    double a[n][m],s=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    double max=a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<"["<<a[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        if((i+1)%2==0){
            for (int j = 0; j <= m; j++){
                if(j<m) {
                    cout<<"["<<a[i][j]<<"]";
                    s+=a[i][j];
                }
                else{
                    cout<<"<"<<s<<">";
                    cout<<endl;
                }
            }
        }
        if(a[i][0]>max) max=a[i][0];
    }
    cout<<max;
    
}
            /**
            
            **/