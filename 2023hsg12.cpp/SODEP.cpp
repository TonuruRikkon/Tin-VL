#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t=0,n;
    cin>>n;
    while (n>0)
    {
        t+=n%10;
        n=n/10;
    }
    if(t%10==9)cout<<1;
    else cout<<0;
    
}