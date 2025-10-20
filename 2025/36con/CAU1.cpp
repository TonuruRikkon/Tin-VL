#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int g=(a,b),tol=0;
    for (int i = 1; i <= n; i++)
    {
        if(g%i==0) tol++;
    }
    cout<<tol;
}