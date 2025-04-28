#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
    cin>>n;
    vector<int> inp,ref=inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    vector<pair<int,int>> ans;
    sort(ref.begin(),ref.end());
    for(int i=0;i<inp.size();i++){
        for (int j = i+1; j < inp.size(); j++)
        {
            if(inp[i]>inp[j]) swap(inp[i],inp[j]);
            ans.push_back({inp[i],inp[j]});
            break;
        }
    }
    cout<<d<<'\n';
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}