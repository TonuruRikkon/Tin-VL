#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; vector<int> s;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        s.emplace_back(x);        
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r,count[10],ans=0;
        memset(count,0,sizeof(count));
        cin>>l>>r;
        for (int j = l-1; j < r-1; j++)
        {
            count[s[j]-1]++;
            if(j==l-1) continue;
            for(int k=s[j]; k<10; k++){
                ans+=count[k];
            }
        }
        cout<<ans<<"\n";
    }
    
}