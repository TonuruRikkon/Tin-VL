#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("SUMOFNEG.INP","r",stdin);
    freopen("SUMOFNEG.OUT","w",stdout);
    int n;
    cin>>n;
    vector<int> inp(n),tol(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
        tol[i+1]=tol[i]+inp[i];
    }
    vector<pair<int,int>> asViTri;
    for (int i = 0; i <= n; i++)
    {
        asViTri.push_back({tol[i],i});
    }
    sort(asViTri.begin(),asViTri.end());
    int ans=0;
    int maxx=0;
    for (int i = 1; i <= n; i++)
    {
        if(maxx>asViTri[i].second){
            ans=max(ans,maxx-asViTri[i].second);
        }
        else{
            maxx= max(maxx,asViTri[i].second);
        }
    }
    
    
    cout<<ans;
    
}