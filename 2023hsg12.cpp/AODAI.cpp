#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s=0;
    cin>>n;
    int a[n+1],b[n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]==4){
            s++;
            a[i]=0;
        }
        else if(a[i]<4&&a[i]!=0){
            for (int j = 0; j < n; j++)
            {
                if(a[i]+a[j]<=4){
                    a[i]+=a[j];
                    a[j]=0;
                }
                if(a[i]==4) break;
            }
            s++;
            a[i]=0;
        }
    }
    cout<<s;
    
}