#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a>x&&b>x&&c>x) cout<<"KHONG";
    else if(a>y&&b>y&&c>y) cout<<"KHONG";
    else cout<<"CO";
    return 0;
}
