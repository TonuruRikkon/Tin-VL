#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

int sua(int k)
{
    int ngay=0,hop=0,het=0;
    for(auto x:mp){
        if(x.first>ngay){
            hop+=k*(x.first-ngay);
            ngay=x.first;
        }
        hop-=x.second;
        if(hop<0){
            het+=abs(hop);
            hop=0;
        }
    }
    return het;
}

int main()
{
    vector<int> inp;
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        inp.push_back(x);
    }
    cout<<sua(k)<<"\n";
    int L=1,R=n,mid,ans=n;
    while(R>=L){
        mid=(L+R)/2;
        if(sua(mid)>0){
            L=mid+1;
        }
        else {
            R=mid-1;
            ans=mid;
        }
    }
    cout<<ans;
}