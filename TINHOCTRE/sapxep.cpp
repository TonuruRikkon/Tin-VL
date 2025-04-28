#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    vector<pair<int,int>> ans;
    vector<int> ref=inp;
    sort(ref.begin(),ref.end());
    if(ref==inp){
        cout<<0;
        return 0;
    }
    for (int i = 0; i <= n/2; i++)
    {
        d++;
        ans.push_back({ref[i],inp[i]});
    }
    cout<<d<<'\n';
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}