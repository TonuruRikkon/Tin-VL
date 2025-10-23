#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp,tol;
    tol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        tol.push_back(tol[i]+x);
    }
    int decreased=0,ans=0;
    for (int i = 2; i <= n; i++)
    {
        if(tol[i-1]-decreased==tol[n]-(tol[i-1])){
            ans++;
            decreased=tol[i-1];
        }
    }
    cout<<ans;
}