#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxX=0,minX=INT_MAX,maxY=0,minY=INT_MAX;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        maxX=max(maxX,x);
        minX=min(minX,x);
        maxY=max(maxY,y);
        minY=min(minY,y);
    }
    long long d=maxX-minX,r=maxY-minY;
    cout<<(d+2)*(r+2);
}