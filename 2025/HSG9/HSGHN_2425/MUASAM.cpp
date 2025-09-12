#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,L,R;
    cin>>n>>L>>R;
    vector<long long> inp;
    long long ans=R;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        inp.emplace_back(x);
    }
    sort(inp.begin(),inp.end());
    long long l=0,r=inp.size()-1;
    while(l<r){
        long long tol=inp[r]+inp[l];
        if(tol>R) r--;
        else if(tol<L) l++;
        else{
            if(tol<ans) ans=tol;
            r--;
        }
    }
    cout<<ans;
}