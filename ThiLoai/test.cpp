#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)];
int tonguoc[int(1e6)];

void ngt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=0;
    int p=2;
    while (p*p<int(1e7))
    {
        for (int i = 2; i < int(1e7)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<int(1e7)&&ngto[p]==false;p++);
    }
    
}

void tongu()
{
    memset(tonguoc,0,sizeof(tonguoc));
    for (int i = 1; i < int(1e6); i++)
    {
        for (int j = i; j < int(1e6); j+=i)
        {
            tonguoc[j]+=i;
        }
        
    }
}

int main()
{
    ngt();
    tongu();
    int x;
    cin>>x;
    cout<<tonguoc[x]<<endl;
    for (int i = 0; i <= x; i++)
    {
        cout<<i<<" ";
        if(i<10) cout<<" ";
    }
    cout<<endl;
    for (int i = 0; i <= x; i++)
    {
        cout<<tonguoc[i]<<" ";
        if(tonguoc[i]<10)cout<<" ";
    }
    cout<<endl;
    for (int i = 0; i <= x; i++)
    {
        if(ngto[i]==true) cout<<i<<" ";
    }
    
    
}