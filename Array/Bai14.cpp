#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
    cin>>n;
    double a[1000];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    double x1=*min_element(a,a+n), x2, pos[1000];
    for(int i=0;i<n;i++){
        if(a[i]!=x1){
            x2=a[i];
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]>x1){
            if(a[i]<x2){
                x2=a[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==x2){
            pos[d]=i;
            d++;
        }
    }
    cout<<"Gia tri nho thu nhi:"<<x2<<endl;
    cout<<"Cac vi tri:";
    for(int i=0;i<d;i++){
        if(i!=d) cout<<pos[i]<<",";
        if(i==d) cout<<pos[i];
    }
}