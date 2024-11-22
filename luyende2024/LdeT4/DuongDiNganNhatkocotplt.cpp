#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(1e6)+1];

int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    
}