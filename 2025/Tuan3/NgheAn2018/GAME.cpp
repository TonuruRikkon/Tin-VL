#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("GAME.INP", "r", stdin);
    // freopen("GAME.OUT", "w", stdout);
    int n;
    cin>>n;
    int first;
    cin>>first;
    vector<int> diff;
    for (int i = 1; i < n; i++)
    {
        int sec;
        cin>>sec;    
        diff.push_back(abs(sec-first));
    }

    int sz=diff.size(), div=0;

    for (int i = 1; i < sz; i++)
    {
        div=gcd(diff[i-1],diff[i]);
    }
    vector<int> ans;
    for (int i = 2; i*i <= div; i++)
    {
        if(div%i==0){
            if(div/i!=i) ans.push_back(div/i);
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<' '; cout<<div;
    
}