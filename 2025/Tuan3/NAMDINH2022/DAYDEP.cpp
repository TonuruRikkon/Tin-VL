#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans=0;
    for (auto &&x : cnt)
    {
        if(x.first!=x.second) ans+=x.second%x.first; 
    }
    cout<<ans;
}