#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,dem=0;
    cin>>n>>m;
    for(n;n<m;n=n+(n/10)) dem++;
    cout<<dem;
}