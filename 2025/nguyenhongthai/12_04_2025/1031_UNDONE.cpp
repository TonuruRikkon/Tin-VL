#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(a*n>b){
        if(n<=m){
            cout<<b;
        }
        else if(a>b){
            cout<<b*(n/m)+b*(n%m);
        }
        else{
            cout<<(n/m)*b+(n%m)*a;
        }
    }
    else{
        cout<<n*a;
    }
}