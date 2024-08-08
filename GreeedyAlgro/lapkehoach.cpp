#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,start=0,end=0;
    cin>>n;
    vector<pair<int,int>> a;
    set<pair<int,int>> ans;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    for(auto i:a){
        if(i.first>=end){
            start = i.first;
            end = i.second;
        }
        ans.insert(make_pair(start,end));
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
}