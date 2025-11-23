#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<double,pair<int,int>>> list;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            list.push_back({double(i)/double(j),{i,j}});
        }
    }
    sort(list.begin(),list.end());
    cout<<0<<'/'<<1<<'\n';
    for(int i=1; i<list.size();i++){
        if(list[i].first!=list[i-1].first&&list[i].second.first!=0) cout<<list[i].second.first<<'/'<<list[i].second.second<<'\n';
    }
    cout<<1<<'/'<<'1';
}