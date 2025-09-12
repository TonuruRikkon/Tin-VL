#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    vector<vector<int>> ans;
    vector<int> temp;
    for (int i = 1; i < n; i++)
    {
        int x1=inp[i-1];
        if(inp[i]<x1){
            temp.push_back(x1);
            ans.emplace_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(x1);
        }
    }
    temp.push_back(inp[n-1]);
    ans.emplace_back(temp);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    cout<<ans.size();
}