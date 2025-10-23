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
    long long toldiv=0,tolmod=0;
    for (int i = 0; i < n; i++)
    {
        toldiv+=(inpx[i]*(lcmy/inpy[i]))/lcmy;
        tolmod+=(inpx[i]*(lcmy/inpy[i]))%lcmy;
    }
    if(toldiv>0)cout<<toldiv<<' ';
    if(tolmod>0)cout<<tolmod<<' '<<lcmy;
}