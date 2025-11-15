#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> w(n);
    vector<vector<int>> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    
}