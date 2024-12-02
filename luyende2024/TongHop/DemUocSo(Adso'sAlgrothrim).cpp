#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7),true);
vector<int> ngt;

void sangnt()
{
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e6))
    {
        ngt.push_back(p);
        for (int i = 2; i < int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

int main()
{
    sangnt();
    vector<int> vecThaiHoang;
    int n;
    cin>>n;
    for(int x:ngt)
    {
        if(x>n) break;
        else{
            int u=x,po=0;
            while (u<=n)
            {
                po+=n/u;
                u*=x;
            }
            if(po!=0)vecThaiHoang.push_back(po);
        }
    }
    int ans=1;
    for(int x:vecThaiHoang){
        ans*=(x+1);
    }
    cout<<ans;
}