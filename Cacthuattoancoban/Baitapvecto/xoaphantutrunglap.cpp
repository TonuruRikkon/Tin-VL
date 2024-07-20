#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> c;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
    }
    sort(c.begin(),c.end());
    auto it = unique(c.begin(),c.end());
    c.erase(it,c.end());
    for(int i:c) cout<<i<<" ";
}