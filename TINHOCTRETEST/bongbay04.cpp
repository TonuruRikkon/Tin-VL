#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> s,L(n);
    fill(L.begin(), L.end(), 1);
    L[0]=0;
    cin>>n;
    s.emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        s.emplace_back(x);
        for (int j = 1; j <= i; j++)
        {
            if(s[i]>s[j]){
                L[i]=max(L[i],L[j]+1);
            }
        }
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<L[r]-L[l-1]<<"\n";
    }
    
}