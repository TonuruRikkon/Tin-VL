#include <bits/stdc++.h> 
using namespace std;

bool ngto[int(1e7)];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
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

int main()
{
    sangnt();
    for (int i = 0; i < 1000; i++)
    {
        if(ngto[i]==true)
        cout<<i<<" ";
    }
    
}