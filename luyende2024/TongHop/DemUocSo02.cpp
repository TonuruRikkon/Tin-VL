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
    map<int,int> mapThaiHoang;
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
            if(po!=0) mapThaiHoang[x]=po;
        }
    }
    int_fast64_t ans=1,ans2=1;
    for(auto x:mapThaiHoang){
        ans*=(x.second+1);
        ans2*=(powl(x.first,x.second+1)-1)/(x.first-1);
    }

    cout<<ans<<" "<<ans2;
}