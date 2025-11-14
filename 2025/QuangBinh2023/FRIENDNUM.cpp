#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FRIENDNUM.INP","r",stdin);
    freopen("FRIENDNUM.OUT","w",stdout);
    int n;
    cin>>n;
    vector<int> inp(n);
    map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
        cnt[inp[i]%3]++;
    }
    int ans=0;
    ans+=cnt[2]*cnt[1]+cnt[0]*(cnt[0]-1)/2;
    cout<<ans;
}