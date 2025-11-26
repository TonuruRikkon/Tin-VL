#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cnt[x%k]++;
    }
    int ans=0;
    for (auto &x : cnt)
    {
        if(x.first==0||x.first==k/2) ans+=x.second*(x.second-1)/2;
        else{
            ans+=x.second*cnt[k-x.first]+x.second*cnt[-x.first];
        }
        x.second=0;
    }
    cout<<ans;
}