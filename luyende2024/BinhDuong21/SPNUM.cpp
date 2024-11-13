#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[1]=ngto[0]=false;
    int p=2;
    while(p*p<int(1e6)){
        for (int i = 2; i < int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

void kiemtra()
{
    for(int x:ngto){
        
    }
}

int main()
{
    int n;
    sangnt();
    while (true)
    {
        n++;

    }
    
}