#include <bits/stdc++.h>
using namespace std;

int uoc[int(1e6)+1];
int tongu[int(1e6)+1];
bool ngto[int(1e6)+1];

bool ngt(int s)
{
    int n=s;
    for (int i = 2; i*i < n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    memset(tongu,1,sizeof(tongu));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e6))
    {
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
            tongu[i*p]+=p;
        }
        tongu[p]+=p;
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

void demuoc()
{
    memset(uoc,0,sizeof(uoc));
    for (int i = 2; i <= int(1e6); i++)
    {
        if(tongu[i]<=int(1e6)){
            if(ngto[tongu[i]]==true) uoc[i]=uoc[i-1]+1;
            else uoc[i]=uoc[i-1];
        }
        else{
            if(ngt(tongu[i])==true) uoc[i]=uoc[i-1]+1;
            else uoc[i]=uoc[i-1];
        }
    }    
}

int main()
{
    int n;
    cin>>n;
    sangnt();
    demuoc();
    if(n<=int(1e6)){
        cout<<uoc[n];
    }
    else{
        if(sqrt(n)*sqrt(n)==n) cout<<uoc[n]+n/uoc[n]-sqrt(n);
        else cout<<uoc[n]+n/uoc[n];
    }
}