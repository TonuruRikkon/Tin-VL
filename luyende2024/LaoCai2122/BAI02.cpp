#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)+1];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e6))
    {
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
    
}

int main()
{
    freopen("BAI02.INP","r",stdin);
    freopen("BAI02.INP","w",stdout);
    int n;
    cin>>n;
    sangnt();
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin>>a;
        int sqrta=sqrt(a);
        if(sqrt(a)==sqrta&&ngto[sqrta]==true)
        {
            cout<<"YES"<<endl;
        } 
        else cout<<"NO"<<endl; 
    }
    
}