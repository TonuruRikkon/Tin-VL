#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,a,b;
    cin>>l>>r>>a>>b;
    int div=(a*b)/__gcd(a,b);
    cout<<r/div-l/div;
}