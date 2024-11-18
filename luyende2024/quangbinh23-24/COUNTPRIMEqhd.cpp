#include <bits/stdc++.h>
using namespace std;

int ngto[int(1e6)+1];
vector<int> tngt,ngt;

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[1]=ngto[0]=false;
    int p=2;
    tngt.push_back(0);
    while (p*p<=int(1e6))
    {
        tngt.push_back(tngt.back()+p);
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
    int x;
    while (cin>>x)
    {
        if(x==1) cout<<1<<endl;
        else{
            
        }
    }
    
}