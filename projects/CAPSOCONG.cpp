#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,mid,fr,bh;
    cin>>a>>b>>c;
    mid = a+b+c-max(max(a,b),c)-min(min(a,b),c);
    fr = mid-min(min(a,b),c);
    bh = max(max(a,b),c)-mid;
    if (fr==bh) cout<<max(max(a,b),c) + bh;
    else if(fr>bh) cout<<mid-bh;
    else cout<<mid+fr;
    return 0;

}
