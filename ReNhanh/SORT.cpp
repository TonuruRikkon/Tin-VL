#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,n_max,n_min;
    cin>>a>>b>>c;
    n_max=max(max(a,b),c);
    n_min=min(min(a,b),c);
    cout<<n_min<<" "<<a+b+c-n_max-n_min<<" "<<n_max;
    return 0;
}
