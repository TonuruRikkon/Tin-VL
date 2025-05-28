#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,xp=0,xn=0,yp=0,yn=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>xp) xp=x;
        else if(x<xn) xn=x;
        if(y>yp) yp=y;
        else if(y<yn) yn=y;
    }
    cout<<(int(xp+1)+int(abs(xn)+1))*(int(yp+1)+int(abs(yn)+1));
    
}