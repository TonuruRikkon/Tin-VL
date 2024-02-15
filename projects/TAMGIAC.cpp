#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c != 180) cout<<"0"<<endl;
    else 
    {
        if(a==b&&b==c) cout<<"DEU"<<endl;
        else {
            if(a==b||b==c||a==c) cout<<"CAN";
            if(a==90||b==90||c==90) cout<<"VUONG"<<endl;
            }
    }
    return 0;
}