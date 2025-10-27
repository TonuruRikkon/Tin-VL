#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    int minn=1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        if(mp[minn]!=0){
            for (int j = minn; j <= int(1e6); j++)
            {
                if(mp[j]==0) {
                    minn=j;
                    break;
                }
            }
        }
        cout<<minn;
        if(i!=n-1) cout<<' ';
    }
    
    
}