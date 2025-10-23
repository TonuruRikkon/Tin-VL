#include <bits/stdc++.h>
using namespace std;

long long SUM(int n, vector<long long> u, vector<long long> v)
{
    int ans=0;
    auto posu=upper_bound(u.begin(),u.end(),n);
    for (int i = 0; i <= posu-u.begin()-1; i++)
    {
        ans++;
    }
    auto posv=lower_bound(v.begin(),v.end(),n);
    for (int i = 0; i <= posv-v.begin()-1; i++)
    {
        ans--;
    }
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> upos,vpos;
    for (long long i = 0; i < n; i++)
    {
        long long u,v;
        cin>>u>>v;
        upos.push_back(u);
        vpos.push_back(v);
    }
    sort(upos.begin(),upos.end());
    sort(vpos.begin(),vpos.end());
    long long q;
    cin>>q;
    for (long long i = 0; i < q; i++)
    {
        long long x;
        cin>>x;
        cout<<SUM(x,upos,vpos);
        if(q!=q-1)cout<<'\n';
    }
    

}