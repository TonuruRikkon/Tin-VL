#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DRB.INP", "r", stdin);
    freopen("DRB.OUT", "w", stdout);
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    int ans=(a1-a2)/(b2-b1);
    if(ans>=0)cout<<ans;
    else cout<<-1;
}