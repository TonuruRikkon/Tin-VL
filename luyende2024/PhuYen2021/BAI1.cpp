#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)+1];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<=int(1e7)){
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e7)&&ngto[p]==false;p++);
    }
}

int main()
{
    sangnt();
    int n;
    cin>>n;
    for (int i = pow(10,n-1); i < pow(10,n); i++)
    {
        int u=i;
        bool acpt=true;
        while(u>0){
            if(ngto[u]==false){
                acpt=false;
                break;
            }
            u/=10;
        }
        if(acpt==true) cout<<i<<endl;
    }
    
}