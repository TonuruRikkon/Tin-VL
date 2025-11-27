#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,p;
    cin>>n>>p;
    if(p%2!=0) p--;
    cout<<min(p/2,(n-p)/2);
}