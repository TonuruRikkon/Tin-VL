#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7),true);
vector<int> ngt;

void sangnt()
{
    fill(ngto.begin(),ngto.end(),true);
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<=int(1e6))
    {
        ngt.push_back(p);
        for(int i=2;i<=int(1e6)/p;i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

int main()
{
    sangnt();
    map<int,int> mp;
    int n,m;
    cin>>n>>m;
    for (int i = 2; i <= n; i++)
    {
        int u=i;
        for(int x:ngt){
            if(u<x) break;
            while(u%x==0)
            {
                mp[x]++;
                u/=x;
            }
        }
    }
    for(auto x:mp){
        cout<<x.first<<":"<<x.second<<" ";
    }
}