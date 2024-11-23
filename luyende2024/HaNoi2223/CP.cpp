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
    sangnt();
    long long a,b;
    int ans=0;
    cin>>a>>b;
    for (int i = a; i <= b; i++)
    {
        long long sqrtx=sqrt(i);
        if(sqrtx*sqrtx==i){
            if(ngto[sqrtx]==true) ans++;
        }
    }
    cout<<ans;
}