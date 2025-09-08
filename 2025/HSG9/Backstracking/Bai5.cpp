#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    vector<double> inp;
    unordered_map<double> pos;
    for (int i = 0; i < n; i++)
    {
        double x,y;
        cin>>x>>y;
        inp.push_back(y/x);
        pos[y/x]=1;
    }
    vector<double> cmp=inp;
    sort(cmp.begin(),cmp.end());
    reverse(cmp.begin(),cmp.end());
    int i=0;
    while(t>0){
        if(i==n) break;
        if(t>cmp[i]){
            t-=cmp[i];
            pos[cmp[i]]=0;
        }
        i++;
    }
    for(auto x:pos){
        cout<<x.second;
    }
}