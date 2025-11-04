#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<long long> inp;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        inp.push_back(x);
    }
    sort(inp.begin(),inp.end());
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        auto up=upper_bound(inp.begin(),inp.end(),r), down=lower_bound(inp.begin(),inp.end(),l);
        cout<<up-down<<'\n';
    }
    

    
}