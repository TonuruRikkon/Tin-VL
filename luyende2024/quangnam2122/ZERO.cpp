#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tol[n+1];
    memset(tol,0,sizeof(tol));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        tol[i]=tol[i-1]+x;
    }
    
}