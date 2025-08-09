#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> tol(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        tol[i]=tol[i-1]+x;
    }
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<tol[y]-tol[x-1]<<'\n';
    }
    
}