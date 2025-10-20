#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> inp;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        inp.push_back(temp);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            inp[i].push_back(x);
        }
    }
    vector<pair<int,int>>ans;
    ans.push_back({1,1});
    int tol=inp[0][0];
    int x=0,y=0;
    while(x!=n-1||y!=n-1)
    {
        if(x!=n-1){
            if(y!=n-1){
                if(inp[x][y+1]<inp[x+1][y]) y++;
                else x++;
            }
            else x++;
        }
        ans.push_back({x+1,y+1});
        tol+=inp[x][y];
    }
    cout<<tol<<'\n';
    for(pair<int,int> x:ans) cout<<x.first<<' '<<x.second<<'\n';
}