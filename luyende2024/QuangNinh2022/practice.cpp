#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> inp;
    int n,c,ans=0;
    cin>>n>>c;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        inp.push_back({a,b});
    }
    sort(inp.begin(),inp.end());
    while (true)
    {
        int pos=lower_bound(inp.begin(),inp.end(),c)-inp.begin();
        if(pos>=inp.size()) break;
        else {
            c+=inp[pos].second;
            ans++;
        }
    }
    
}