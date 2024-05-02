#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double a[1000];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    double x,d;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            x=a[i];
            d=i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            if(a[i]>x){
                x=a[i];
                d=i;
            }
        }
        
    }
    cout<<x<<":"<<d;  
}