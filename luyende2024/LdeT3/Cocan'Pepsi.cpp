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
        ngt.push_back(p);
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

int main()
{
    int n;
    sangnt();
    cin>>n;
    for(int x:ngt){
        if(x>n) break;
        else cout<<x<<" ";
    }
}