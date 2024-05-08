#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=1,y=0;
    cin>>n;
    double a[1000],dem[1000];
    memset(dem,0,1000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double x=a[0];
    for(int i=1;i<n;i++){
        if(x<a[i]){
            x=a[i];
            d++;
        }
        else{
            dem[y]=d;
            y++;
            d=1;
            x=a[i];
        }
    }
    if(a[n-1]>=a[n]){
        dem[y]=d;
        y++;
        d=1;
    }
    cout<<*max_element(dem,dem+n);
}