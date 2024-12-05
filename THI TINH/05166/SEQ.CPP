#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int_fast64_t> inp,tol(n+1,0),inp2;
    for(int i=1;i<=n;i++){
        int_fast64_t x;
        cin>>x;
        inp.push_back(x);
        tol[i]=tol[i-1]+x;
    }
    for(int i=0;i<m;i++){
        int_fast64_t y;
        cin>>y;
        inp2.push_back(y);
        auto temp=lower_bound(tol.begin()+1,tol.end(),y);
        if(*temp!=y) cout<<-1<<" ";
        else cout<<temp-tol.begin()<<" ";
    }
}
