#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("GIAODICH.INP","r",stdin);
    freopen("GIAODICH.OUT","w",stdout);
    int n;
    long long ref=0,d=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(ref<0&&x>=0){
            ref=x;
        }
        else{
            ref+=x;
        }
        if(ref>d)d=ref;
    }
    cout<<d;
}