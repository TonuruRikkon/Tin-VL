#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long d=0;
    unsigned long long a,a1,a2,a3,a4;
    cin>>a>>a1>>a2>>a3>>a4;
    if(a1>=a3){
        //Tinh a3
        a1-=a3;
        d+=a3*2;
        a3=0;
        //Tinh a2
        if(a1/2>=a2){
            a1-=a2*2;
            d+=a2*4;
            a2=0;
        }
        else{
            a2-=a1/2;
            d+=a1*2;
            a1=0;
        }
        d+=ceil(double(a1)*3/4)+(a1-ceil(double(a1)*3/4))*3;
        d+=(a2/2)*4+(a2%2)*2;
    }
    else if(a1<a3){
        a3-=a1;
        d+=a1*2;
        a1=0;
        if(a3>=a2*2){
            a3-=a2*2;
            d+=a2*3;
            a2=0;
        }
        else{
            a2-=ceil(double(a3)/2);
            d+=a3+(ceil(double(a3)/2)*2);
            a3=0;
        }
        d+=ceil(double(a3)/4)*3+(a3-ceil(double(a3)/4));
        d+=(a2/2)*4+(a2%2)*2;
    }
    cout<<d;
}