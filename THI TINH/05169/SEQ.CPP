#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    int n,m; cin>>n>>m;
    vector<int>a;
    vector<int>b(m);
    vector<int>cd(n,0);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        cd[i]+=a[i];
        if(i>0)cd[i]=cd[i-1]+a[i];
    }
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++){
        int x=lower_bound(cd.begin(),cd.end(),b[i])-cd.begin();
        if(binary_search(cd.begin(),cd.end(),b[i])) cout<<x+1<<" ";
        else cout<<-1<<" ";
    }
}


