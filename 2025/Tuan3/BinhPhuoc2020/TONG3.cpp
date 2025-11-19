#include<bits/stdc++.h>
using namespace std;
int main(){
    const long long MAX=1e9+7;
    long long n,k,p,tong=0; cin>>n>>k>>p;
    vector<long long>vl(n);
    for(int i=0;i<n;++i){
        cin>>vl[i];
        tong+=vl[i];
    }
    long long duk,dup,thuank,ans=0,length=n;
    thuank=k/length;
    duk=k%length;
    dup=p%length;
    for(int i=dup-1;i<duk;++i) ans+=vl[i]%MAX;
    long long result=ans%MAX+((tong%MAX)*(thuank%MAX))%MAX;
    cout<<result;
}