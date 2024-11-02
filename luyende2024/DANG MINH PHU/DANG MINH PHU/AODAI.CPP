#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("AODAI.INP","r",stdin);
    freopen("AODAI.OUT","w",stdout);
    int n;
    cin>>n;
    map<int,int> inp;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        inp[x]++;
    }
    int ans=0;
    if(inp[3]>=inp[1]){
        inp[3]-=inp[1];
        inp[4]+=inp[1];
        inp[1]=0;
    }
    else if(inp[3]<inp[1]){
        inp[1]-=inp[3];
        inp[4]+=inp[3];
        inp[3]=0;
    }
    inp[4]+=inp[2]/2;
    inp[2]=inp[2]%2;
    if(inp[2]==1&&inp[1]>=2){
        inp[1]-=2;
    }
    else if(inp[1]<2){
        inp[1]=0;
    }
    ans+=inp[4]+inp[3]+inp[2]+inp[1];
    cout<<ans;
}
