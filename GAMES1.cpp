#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,n_max,n_min,mid,d1,d2,x;
    cin>>a>>b>>c;
    n_max=max(max(a,b),c);
    n_min=min(min(a,b),c);
    mid=a+b+c-n_max-n_min;
    d1=mid - n_min-1;
    d2=n_max-mid-1;
    x=max(d1,d2);
    if(x%2==1) cout<<x/2+2;
    else cout<<x/2+1;
    return 0;
}
