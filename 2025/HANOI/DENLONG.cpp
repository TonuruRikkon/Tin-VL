#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> inp;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        mp[x]++;
    }

    int l=0,r=n-1,ans=0,tol=mp.size();
    vector<int> maxx(k+1,0);
    for(auto x:mp){
        for(int y:maxx){
            if(x.second>mp[y]) mp[y]=x.first;
        }
    }

    while(l<r)
    {
        mp[inp[l]]--;
        if(mp[inp[l]]==0) tol--;
        if(tol==k){
            ans=max(r-l+1,ans);
        }
        mp[inp[r]]--;
        if(mp[inp[r]]==0) tol--;
        if(tol==k){
            ans=max(r-l+1,ans);
        }
        l++;
        r--;
    }
    cout<<ans;
}