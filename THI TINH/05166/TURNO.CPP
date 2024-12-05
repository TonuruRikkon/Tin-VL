#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TURNO.INP","r",stdin);
    freopen("TURNO.OUT","w",stdout);
    map<int,int> mp;
    int n;
    int_fast64_t ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=5) continue;
        else if(x<=10) mp[10]++;
        else if(x<=15) mp[15]++;
        else if(x>=60) mp[60]++;
        else mp[1]++;
    }
    long long three_t=300;
    for(auto x:mp){
        if(x.first==10) ans+=(three_t-(300*80)/100)*x.second;
        else if(x.first==15) ans+=(three_t-(300*50)/100)*x.second;
        else if(x.first==60) ans+=(three_t-(300*20)/100)*x.second;
        else if(x.first==1) ans+=(three_t)*x.second;
    }
    cout<<ans<<"000";
}
