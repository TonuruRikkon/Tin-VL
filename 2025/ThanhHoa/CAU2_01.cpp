#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    int d=1;
    for (int i = 1; i < inp.size(); i++)
    {
        if(inp[i]<inp[i-1]) d++;
    }
    cout<<d;
}