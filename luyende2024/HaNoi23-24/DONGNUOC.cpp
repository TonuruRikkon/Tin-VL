#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,d=0;
    cin>>n;
    d=n/5;
    if(n%5==4)d+=2;
    else if(n%5>0)d++;
    cout<<d;
}