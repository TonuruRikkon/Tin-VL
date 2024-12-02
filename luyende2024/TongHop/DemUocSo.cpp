#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7)+1,true);
vector<int> ngt;

void sangnt()
{
    fill(ngto.begin(),ngto.end(),true);
    fill(ngt.begin(),ngt.end(),0);
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<=int(1e7))
    {
        ngt.push_back(p);
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e7)&&ngto[p]==false;p++);
    }
    
}

int main()
{
    sangnt();
    map<int,int> mp;
    int n,ans=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        int u=i;
        for(int x:ngt){
            while(u%x==0){
                mp[x]++;
                u/=x;
            }
        }
        if(u>1){
            mp[u]++;
        }
    }

    for(auto x:mp){
        ans*=(x.second+1);
    }
    cout<<ans;
}