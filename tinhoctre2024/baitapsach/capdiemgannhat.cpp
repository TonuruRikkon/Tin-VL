#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
    float ans;
    cin>>n;
    vector<pair<int,int>> xyz;
    vector<float> pos;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        xyz.push_back(make_pair(x,y));
    }
    for (int i = 1; i < n; i++)
    {
        double x1,y1;
        x1=xyz[i].first-xyz[i-1].first;
        y1=xyz[i].second-xyz[i-1].second;
        pos.push_back(sqrt(x1*x1+y1*y1));
        d++;
    }
    ans =*min_element(pos.begin(),pos.end());
    cout<<fixed<<setprecision(3)<<ans;
}