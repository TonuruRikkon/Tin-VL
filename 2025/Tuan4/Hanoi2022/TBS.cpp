#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long double a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+b+c+d>0) cout<<1;
    else if(a+b+c+d<0) cout<<-1;
    else cout<<0;
}