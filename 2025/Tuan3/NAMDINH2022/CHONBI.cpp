#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>> inp;
    for (int i = 0; i < m; i++)
    {
        long long a,b;
        cin>>a>>b;
        inp.push_back({b,a});
    }
    sort(inp.begin(),inp.end(),greater<pair<long long,long long>>());
    long long ans=0;
    for(auto[b,a]:inp){
        if(n<=0) break;
        ans+=min(a,n)*b;
        n-=a;
    }
    cout<<ans;
}