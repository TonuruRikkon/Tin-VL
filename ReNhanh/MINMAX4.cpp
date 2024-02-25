#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(min(min(a,b),c),d)<<" "<<max(max(max(a,b),c),d);
    return 0;
}