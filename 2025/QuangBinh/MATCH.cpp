#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;
    vector<int> a,b,c,d;
    map<int,int> tolab;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        d.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tolab[a[i]+b[j]]++;
        }
        
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(tolab[l-(c[i]+d[j])]>0){
                ans+=tolab[l-(c[i]+d[j])];
            }
        }
        
    }
    cout<<ans;
}