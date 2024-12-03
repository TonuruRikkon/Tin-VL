#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    long long x=a%m;
    long long y=b%(m-1);
    long long z=x;
    for (int i = 1; i < y; i++)
    {
        z*=m;
        z%=m;
    }
    cout<<z;
}