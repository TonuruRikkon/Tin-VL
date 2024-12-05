#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1), b(m);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=a[i-1]+x;
    }
    a.erase(a.begin());
    for(int i=0;i<m;i++)
    {
        int y;
        cin>>y;
        int ktra=lower_bound(a.begin(),a.end(),y)-a.begin();
        if(ktra<a.size()) cout<<ktra+1<< " ";
        else cout<<"-1"<<" ";
    }
}
