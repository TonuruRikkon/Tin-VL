#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long> inpx,inpy;
    long long lcmy=1;
    for (int i = 0; i < n; i++)
    {
        long long x,y;
        cin>>x>>y;
        inpx.push_back(x);
        inpy.push_back(y);
        lcmy=lcm(lcmy,y);
    }
    long long tol=0;
    for (int i = 0; i < n; i++)
    {
        tol+=inpx[i]*(lcmy/inpy[i]);
    }
    if(tol>=lcmy)cout<<tol/lcmy<<' ';
    if(tol!=lcmy)cout<<tol%lcmy<<' '<<lcmy;
}