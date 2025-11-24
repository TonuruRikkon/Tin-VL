#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> inp;
    vector<int> as(int(1e5)+1,0);
    int minn=INT_MAX;
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin>>x;
        minn=min(minn,x);
        inp.push_back({x,-(i+1)});
    }
    if(minn>n){
        cout<<-1;
        return 0;
    }
    sort(inp.begin(),inp.end());
    
    
    for(auto x:inp){
        while(n-x.first>=0){
            cout<<-(x.second);
            n-=x.first;
        }
    }
    
    
}