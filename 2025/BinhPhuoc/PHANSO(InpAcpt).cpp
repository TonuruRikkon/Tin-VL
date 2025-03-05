#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("PHANSO_N100.INP","r",stdin);
    freopen("PHANSO.OUT","w",stdout);
    map<int,long long> mp;
    int n,exp=0;
    int_fast64_t largest=1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int_fast64_t x,y;
        cin>>x>>y;
        mp[y]+=x;
        if(mp[y]>=y) {
            exp+=mp[y]/y;
            mp[y]=mp[y]%y;
        }
        if(largest%y!=0) largest=lcm(largest,y);
    }
    int_fast64_t tol=0;
    for(auto x:mp){
        tol+=x.second*(largest/x.first);
        cout<<x.first<<" "<<x.second<<" "<<largest<<"\n";
    }
    if(exp>0) {
        if(tol>0)cout<<exp<<" "<<tol<<" "<<largest;
        else cout<<exp;
    }
    else  cout<<tol<<" "<<largest<<" ";
    
}