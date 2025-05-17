#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> inp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int v,s;
        cin>>v>>s;
        inp.emplace_back(make_pair(v,s));
    }

    sort(inp.begin(),inp.end());

    int q;
    cin>>q;



    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        int start=lower_bound(inp.begin(),inp.end(), make_pair(x,INT_MIN))-inp.begin();
        int ends=upper_bound(inp.begin(),inp.end(),make_pair(y,INT_MIN))-inp.begin();
        auto max_it=max_element(start, ends-1, [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        cout<<max_it->second;
    }
    
}