#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,max_int,min_int;
    cin>>a>>b>>c>>d>>e;
    max_int = max(max(max(max(a,e),b),c),d);
    min_int = min(min(min(min(a,e),b),c),d);
    cout<<a+b+c+d+e-max_int<<" "<<a+b+c+d+e-min_int;
    return 0;
}
