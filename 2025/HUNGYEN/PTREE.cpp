#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> inp;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    sort(inp.begin(),inp.end());

    int l=0,r=1,ans=0,sz=inp.size();
    if(inp[r]-inp[l]<=k) ans++;
    while (l<r)
    {
        if(inp[r]-inp[l]<=k){
            ans++;
            if(r!=sz-1) r++;
            else l++;
        }
        else l++;
    }
    cout<<ans;
    
    
}