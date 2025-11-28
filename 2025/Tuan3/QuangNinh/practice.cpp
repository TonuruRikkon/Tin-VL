#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long c;
    cin>>n>>c;
    vector<pair<int,long long>> inp;
    for (int i = 0; i < n; i++)
    {
        int a;
        long long b;
        cin>>a>>b;
        inp.push_back({a,b});
    }
    sort(inp.begin(),inp.end());
    int ans=0;
    for(auto[a,b]:inp)
    {
        if(c<a) break;
        c+=b;
        ans++;
    }
    cout<<ans;
}