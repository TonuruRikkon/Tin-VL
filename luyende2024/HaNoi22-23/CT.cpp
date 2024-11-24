#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    inp.push_back(0);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(inp[i-1]+x);
    }
    
}