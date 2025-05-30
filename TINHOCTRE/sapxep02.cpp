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
    for (int i = 0; i <= n; i++)
    {
        auto it=min_element(inp.begin()+i,inp.end());
        int x=*it;
        if(inp[i]==x) break;
        ans.push_back({x,inp[i]});
        swap(inp[it-inp.begin()],inp[i]);
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}