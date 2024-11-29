#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> mp;
    int n,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        if(ans<mp[x]) ans=mp[x];
    }
    cout<<mp.size()<<"\n";
    cout<<ans;
}