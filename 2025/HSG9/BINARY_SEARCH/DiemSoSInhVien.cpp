#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp,tol;
    tol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        tol.push_back(tol[i]+x);
    }
    int l,r;
    cin>>l>>r;
    cout<<(upper_bound(inp.begin(),inp.end(),r)-inp.begin())-(lower_bound(inp.begin(),inp.end(),l)-inp.begin());
}