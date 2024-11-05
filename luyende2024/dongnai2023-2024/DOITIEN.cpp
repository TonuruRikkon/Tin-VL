#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DOITIEN.INP", "r", stdin);
    freopen("DOITIEN.OUT", "w", stdout);
    int n;
    cin>>n;
    if(n%50000==0) cout<<0;
    else cout<<50000-n%50000;
}