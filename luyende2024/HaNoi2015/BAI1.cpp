#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d=0;
    cin>>a>>b>>c;
    for (int x = 0; x < c/a; x++)
    {
        if((c-(a*x))%b==0){
            int y=(c-(a*x))/b;
            if(y!=0&&__gcd(x,y)==1){
                d++;
            }
        }
    }
    cout<<d;
}