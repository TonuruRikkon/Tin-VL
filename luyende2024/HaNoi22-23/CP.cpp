#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)+1];
vector<int> ngt;

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
    long long a,b,ans=0;
    sangnt();
    cin>>a>>b;
    for (long long i = a; i <= b; i++)
    {
        long long sqrti=sqrt(i);
        if(sqrti*sqrti==i){
            if(ngto[sqrti]==true){
                ans++;
            }
        }
    }
    cout<<ans;
}