#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> adj[n];
    map<pair<int,int>,int> a;
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    
}