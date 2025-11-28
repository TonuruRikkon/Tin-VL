#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> inp;
    for (int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        inp.push_back({u,v});
    }
    sort(inp.begin(),inp.end());
    int ans=0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(inp[j].second>inp[i].second) ans++;
        }
        
    }
    cout<<ans;
}