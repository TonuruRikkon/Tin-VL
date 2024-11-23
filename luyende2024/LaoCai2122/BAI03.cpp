#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("BAI03.INP","r",stdin);
    freopen("BAI03.OUT","w",stdout);
    vector<long long> tol;
    tol.push_back(0);
    int n,s;
    cin>>n>>s;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin>>a;
        tol.push_back(tol[i-1]+a);
    }
    long long L=1, R=n,mid,ans=0;
    while (L<=R)
    {
        mid=(L+R)/2;
        if((tol[R]-tol[L])>=s){
            L=mid+1;
            ans=R-L+1;
        }
        else R=mid-1;
    }
    cout<<ans;
    
}