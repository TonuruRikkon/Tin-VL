#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    map<int,int> mp;
    vector<int> giatri;
    for (int i = 0; i < n; i++)
    {
        int t,m;
        cin>>t>>m;
        giatri.push_back(m);
        mp[t]=max(mp[t],m);
    }
    int d=1;
    vector<int> outp(n,0);
    for (auto x:mp)
    {
        int it=find(giatri.begin(),giatri.end(),x.second)-giatri.begin();
        outp[it]=d++;
        ans+=x.second;
    }
    for(int x:outp){
        if(x==0) cout<<d++<<endl;
        else cout<<x<<endl;
    }
    cout<<ans;
}