#include <bits/stdc++.h>
using namespace std;

int main()
{
    int_fast64_t temp;
    int_fast64_t n,a,b;
    cin>>n>>a>>b;
    temp=(a*b)/__gcd(a,b);
    cout<<n/temp;
}