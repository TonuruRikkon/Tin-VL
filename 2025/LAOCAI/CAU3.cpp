#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    int maxx=INT_MIN,minn=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]=1;
        maxx=max(maxx,x);
        minn=min(minn,x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]=2;
        maxx=max(maxx,x);
        minn=min(minn,x);
    }
    int check = 0,ans=0;
    for (int i = minn; i <= maxx; i++)
    {
        if(check==mp[i]){
            check=0;
            ans++;
        }
        else if(mp[i]==1) check=2;
        else if(mp[i]==2) check=1;
    }
    cout<<ans;
    

    
}