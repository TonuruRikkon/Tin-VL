#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> inp(n);
    vector<long long> tol(n+1);
    unordered_map<int,int> cnt;
    cnt[0]=1;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
        tol[i+1]=tol[i]+inp[i];
        ans+=cnt[tol[i+1]-k];
        cnt[tol[i+1]]++;
    }
    cout<<ans;

}