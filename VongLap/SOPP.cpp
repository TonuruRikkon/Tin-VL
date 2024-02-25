#include <bits/stdc++.h>
using namespace std;

int tong_uoc(int n)
{
    int x=1,s=0;
    while (x<n)
    {
        if(n%x==0) s=s+x;
        x++;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    if(tong_uoc(n)>n) cout<<"1";
    else cout<<"0";
}