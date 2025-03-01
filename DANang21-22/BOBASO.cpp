#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> s,Ai,Aij;
    long long n,min_el=INT_MAX,max_el=0,max_comp=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(max_el<x) max_el=x;
        s.emplace_back(x);
        Ai.push_back(max_el);
    }
    Aij.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if(max_comp<Ai[i-1]*3+2*s[i]) max_comp=Ai[i-1]*3+2*s[i];
        Aij.push_back(max_comp);
        cout<<Ai[i-1]<<" "<<s[i]<<" "<<Aij[i]<<"\n";
    }
    cout<<"\n-----------------\n";
    long long ans=0;
    for (int i = 2; i < n; i++)
    {
        long long comp=Aij[i-1]-5*s[i];
        ans=max(ans,comp);
        cout<<Aij[i-1]<<" "<<comp<<" "<<ans<<"\n";
    }
    cout<<ans;
}