#include <bits/stdc++.h>
using namespace std;

vector<int> ngt;
bool ngto[3*int(1e7)+1];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=3*int(1e7))
    {
        ngt.push_back(p);
        for (int i = 2; i <= (3*int(1e7))/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=3*int(1e7)&&ngto[p]==false;p++);
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    sangnt();
    for (int i = a+b+1; i <= 3*int(1e7); i++)
    {
        if(ngto[i]==true) {
            cout<<i-(a+b);
            break;
        }
    }
    
}