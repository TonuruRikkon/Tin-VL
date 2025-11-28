#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> inp(n),tol(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
        tol[i+1]=tol[i]+inp[i];
    }
    vector<bool> checked(n,false);
    pair<int,int> out={1,1};
    for (int i = n; i > 0; i--)
    {
        int ref=tol[i]%k;
        if(checked[ref]==true) continue;
        checked[ref]=true;
        auto it=lower_bound(tol.begin(),tol.end(),ref);
        int pos=it-tol.begin();
        if(*it!=ref) continue;
        if(out.second-(out.first-1)<i-pos+1){
            out={pos+1,i};
        }
    }
    if(out==make_pair(1,1)) cout<<0;
    else cout<<out.first<<' '<<out.second;
}