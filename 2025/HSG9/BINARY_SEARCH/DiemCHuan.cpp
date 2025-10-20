#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    int m;
    cin>>m;
    cout<<inp[upper_bound(inp.begin(),inp.end(),m)-inp.begin()-1];
}