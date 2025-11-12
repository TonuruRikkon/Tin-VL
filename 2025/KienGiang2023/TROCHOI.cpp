#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("TROCHOI.INP","r", stdin);
    freopen("CHOCHOI.OUT","w",stdout);
    int n;
    cin>>n;
    int maxx=0,pos=-1;
    map<int,int> tke;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        tke[x]++;
        if(tke[x]>maxx){
            maxx=tke[x];
            pos=x;
        }
    }
    cout<<pos<<' '<<maxx;
}