#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long maxx=max({a,b,c});
        long long minn =min({a,b,c});
        cout<<2*max(0LL,(maxx-minn-2));
        if(i!=q-1) cout<<'\n';
    }
    
}