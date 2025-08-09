#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    a=a%10;
    if(a==0) cout<<0;
    else if(a==1) cout<<1;
    else if(a==5) cout<<5;
    else if(a==6) cout<<6;
    else if(a==9) {
        if(b%2==0) cout<<9;
        else cout<<1;
    }
    else{
            if(b%4==0) cout<<a;
            else{
                b=b%4;
                for (int i = 0; i < b; i++)
                {
                    a=(a*a)%10;
                }
                cout<<a;
            }
    }
}