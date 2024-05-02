#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a[1000],d=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0){
            d++;
            sum+=a[i];
        }
    }
    cout<<d<<endl<<sum;
}