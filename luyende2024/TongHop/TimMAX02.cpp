#include <bits/stdc++.h>
using namespace std;

map<int,int> thuaso(int m)
{
    map<int,int> mp;
    for (int i = 2; i*i <= m; i++)
    {
        while(m%i==0){
            mp[i]++;
            m/=i;
        }
    }
    if(m>1){
        mp[m]++;
    }
    return mp;
}

int thuasoGT(int n,int p)
{
    int d=0;
    while(n%p==0)
    {
        d+=n/p;
        n/=p;
    }
    return d;
}

int giaithua(int n,int m)
{
    int k=INT_MAX;
    map<int,int> mp=thuaso(m);
    for(auto x:mp){
        int p=x.first;
        int e=x.second;
        k=min(k,thuasoGT(n,p)/e);
    }
    return k;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<giaithua(n,m);
}