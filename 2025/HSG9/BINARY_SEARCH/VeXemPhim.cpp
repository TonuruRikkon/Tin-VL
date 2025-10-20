#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inp,tol(n+1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    sort(inp.begin(),inp.end());
    for(int i=0;i<n;i++){
        tol[i+1]=tol[i]+inp[i];
    }
    cout<<upper_bound(tol.begin(),tol.end(),m)-tol.begin()-1;
}