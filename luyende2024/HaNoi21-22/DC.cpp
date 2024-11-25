#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    long long maxR=0,minL=1e18;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        long long x,y;
        cin>>x>>y;
        maxR=max(maxR,x);
        minL=min(minL,y);
        
    }
    
}