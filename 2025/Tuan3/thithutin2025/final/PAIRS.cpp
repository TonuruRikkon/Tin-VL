#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PAIRS.INP", "r", stdin);
    freopen("PAIRS.OUT", "w", stdout);
    int n;
    cin>>n;
    vector<int> inp(n);
    vector<long long> cnt(int(1e6),0);
    int maxx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
        cnt[inp[i]]++;
        maxx=max(maxx,inp[i]);
    }
    long long ans=0;
    for (int i = 1; i <= maxx; i++)
    {
        if(cnt[i]==0) continue;
        if(cnt[i]>=2) ans+=cnt[i]*(cnt[i]-1)/2;
        for (int j = i+i; j <= maxx; j+=i)
        {
            ans+=cnt[i]*cnt[j];
        }
    }
    cout<<ans;
    
}