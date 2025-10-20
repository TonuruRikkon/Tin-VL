#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp,tol;
    tol.emplace_back(0);
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
        tol.emplace_back(tol[i]+x);
    }
    vector<float> avg(n+1,0);
    for (int i = 1; i < n+1; i++)
    {
        avg[i]=tol[i]/i;
    }
    float miin=INT_MAX,ans=0;
    for (int r = k; r < n; r++)
    {
        miin=min(miin,avg[r-k]);
        ans=max(ans,avg[r]-miin);
    }
    cout<<ans;   
}