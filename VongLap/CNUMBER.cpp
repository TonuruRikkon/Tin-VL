#include <bits/stdc++.h>
using namespace std;

    int kiemso(int n)
{
    int s=0;
    while(n!=0){
        if(n%10!=6&&n%10!=8){
            s=1;
            break;
        }
        n=n/10;
    }
    return s;
}

int main()
{
    int n,dem=0;
    cin>>n;
    for(int i=6;i<n;i++){
        if(kiemso(i)==0) {
            dem++;
        }
        }
    cout<<dem;
}