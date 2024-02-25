#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,d=0;
    cin>>a>>b;
    if(a>=3&&b<=4) {cout<<1<<" ";d++;};
    if(a<=6&&b>=2) {cout<<2<<" ";d++;};
    if(a<=2&&b<=3) {cout<<3;d++;};
    if(d<1) cout<<0;
    return 0;
}
