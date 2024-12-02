#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    if(!mp[0]){
        cout<<0;
        return 0;
    }
    else{
        for(auto x:mp){
            if(!mp[x.first+1]&&x.first!=int(1e9)){
                cout<<x.first+1;
                break;
            }
        }        
    }

}