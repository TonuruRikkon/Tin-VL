#include <bits/stdc++.h>
using namespace std;

vector<int> inp[int(1e6)];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        inp[x].push_back(y);
        inp[y].push_back(x);
    }
    
}