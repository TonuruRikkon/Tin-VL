#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,minn,maxx=0,rt=0,d=0,wt=0,x;
    cin>>n;
    pair<int,int> bo[5000+1];
    vector<pair<int,int>> c;
    vector<pair<int,int>> m;
    for (int i = 0; i < n; i++)
    {
        cin>>bo[i].first>>bo[i].second;
    }
    sort(bo,bo+n);
    minn=bo[0].first;
    for (int i = 1; i < n; i++)
    {
        if(bo[i].first<=bo[i-1].second) x=bo[i].second;
        else{
            c.push_back(make_pair(minn,x));
            minn=bo[i].first;
            m.push_back(make_pair(bo[i].first,bo[i-1].second));
            x=bo[i].second;
            d++;
        }
    }
    c.push_back(make_pair(minn,x));
    m.push_back(make_pair(bo[n-1].first,bo[n-2].second));
    d++;
    for (int i = 0; i < d; i++)
    {
        if(c[i].second-c[i].first>wt)wt=c[i].second-c[i].first;
        if(m[i].first-m[i].second>rt) rt=m[i].first-m[i].second;
    }
    cout<<wt<<" "<<rt;
    
}