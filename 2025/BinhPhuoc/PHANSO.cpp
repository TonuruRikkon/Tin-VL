#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,long long> mp;
    int n,largest=0,exp=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x,y;
        cin>>x>>y;
        mp[y]+=x;
        if(mp[y]>=y) {
            exp+=mp[y]/y;
            mp[y]=mp[y]%y;
        }
        largest=max(largest,int(y));
    }
    int_fast64_t tol=0;
    for(auto x:mp){
        if(largest%x.first!=0) largest*=x.first;
        tol+=x.second*(largest/x.first);
    }
    if(exp>0) {
        if(tol>0)cout<<exp<<" "<<tol<<" "<<largest;
        else cout<<exp;
    }
    else  cout<<tol<<" "<<largest<<" ";
    
}