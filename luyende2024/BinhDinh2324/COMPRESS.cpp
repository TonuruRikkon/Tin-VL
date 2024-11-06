#include <bits/stdc++.h>
using namespace std;

long long demle(long long a,long long b)
{
    long long x=b-a+1;
    if(x%2==0){
        return x/2;
    }
    else{
        return ceil(double(x)/2);
    }
}

long long demdb(long long a,long long b)
{
    long long x,y;
    if(b%12>=6) x=ceil(double(b)/12);
    else x=b/12;
    if(a%12>=6) y=ceil(double(a)/12);
    else y=a/12;
    if(a%12==6) return x-y+1;
    else return x-y;
}

int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<demle(a,b)+((b-a)+1-demle(a,b)-demdb(a,b))*2+demdb(a,b)*3;
}