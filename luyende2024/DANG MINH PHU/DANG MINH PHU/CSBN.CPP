#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("CSBN.INP","r",stdin);
    freopen("CSBN.OUT","w",stdout);
    int n,d=0;
    cin>>n;
    map<int, int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp[x]++;
    }
    for(auto x:inp){
        if(x.second!=1) {
            d+=(x.second*(x.second-1))/2;
            }
    }
    cout<<d;
}
