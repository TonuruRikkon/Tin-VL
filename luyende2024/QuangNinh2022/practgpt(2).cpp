#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> inp;
    int n,ans=0;
    long long c;
    cin>>n>>c;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        inp.push_back({a,b});
    }
    sort(inp.begin(),inp.end());
    for(auto x:inp){
        if(x.first<=c){
            c+=x.second;
            ans++;
        }
        else break;
    }
    cout<<ans;
}