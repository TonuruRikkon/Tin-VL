#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TURNO.INP","r",stdin);
    freopen("TURNO.OUT","w",stdout);
    long long n,ans=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(auto z:v){
        if(z<=5) continue;
        else if(z>5 and z<=10) ans+=300000*0.2;
        else if(z>10 and z<=15) ans+=300000*0.5;
        else if(z>15 and z<60) ans+=300000;
        else if(z>=60) ans+=300000*0.8;
    }cout<<ans;
}
