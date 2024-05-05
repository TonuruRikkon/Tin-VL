#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,y=0,d=0;
    cin>>n;
    double a[1000],x[1000];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<0){
            y+=a[i];
            d++;
        }
        else{
            x[d]=y;
            d=0;
            y=0;
        }
    }
    if(a[n-1]<0){
        x[d]=y;
        d=0;
        y=0;
    }
    cout<<max_element(x,x+n)-x;
}