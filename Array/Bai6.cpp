#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a[1000];
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    for(int i=0; i<n;i++){
        if(a[i]<0){
            cout<<i;
            break;
        }
    }
}