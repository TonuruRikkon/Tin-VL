#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a;
    vector<pair<int,int>> sf;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int m;
    cin>>m;
    sort(a.begin(),a.end());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<(upper_bound(a.begin(),a.end(),y)-a.begin())-(lower_bound(a.begin(),a.end(),x)-a.begin())<<endl;
    } 
}