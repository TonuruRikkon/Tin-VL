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
        int ends=lower_bound(inp.rbegin(),inp.rend(), make_pair(y,INT_MIN))-inp.rbegin();
        cout<<start<<' '<<ends<<'\n';
        max_element(inp.begin(), inp.end(), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
    }
    
}