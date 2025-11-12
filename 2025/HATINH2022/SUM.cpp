#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("SUM.INP","r", stdin);
    freopen("SUM.OUT","w", stdout);
    int amogus,ans=0;
    cin>>amogus;
    vector<int> inp,tol(amogus+1,0);
    map<long long,int> cnt;
    cnt[0]=1;   
    for (int i = 0; i < amogus; i++)
    {
        int skibidi;
        cin>>skibidi;
        inp.push_back(skibidi);
        tol[i+1]=tol[i]+skibidi;
        cnt[tol[i+1]]++;
    }
    for(auto x:cnt){
        if(x.second>=2) ans+=x.second*(x.second-1)/2;
    }
    cout<<ans;
}