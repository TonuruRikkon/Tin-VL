#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)+1];
int tonguoc[int(1e6)+1];
\
int sangnt()
{
    memset(ngto,true,sizeof(ngto));
    memset(tonguoc,0,sizeof(tonguoc));
    ngto[0]=ngto[1]=false;
    tonguoc[1]=1;
    int p=2;
    while(p*p<=int(1e6)){
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
            tonguoc[i*p]
        }
        
    }
}

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        cout<<tonguoc(x)<<" ";
    }
    
}