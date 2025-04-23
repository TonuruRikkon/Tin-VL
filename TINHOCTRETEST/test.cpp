#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,x,y,ans;
    cin>>n;vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cin>>q;
    while(q--){
        cin>>x>>y;vector<int> d(11,0);ans=0;
        for(int i=x;i<=y;i++){
            d[s[i]]++;
            if(i==x) continue;
            for(int j=s[i]+1;j<=10;j++){
                ans+=d[j];
            }
        }
        cout<<ans<<"\n";
    }
}