#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int,vector<int>> tol;
    vector<int> inp,ans(n);
    for (int i = 0; i < n; i++)
    {
        int x=s[i]-'0';
        tol[x].push_back(i);
    }
    for(int m:tol[4]){
        tol[8].push_back(m);
    }
    tol.erase(4);
    for(auto x:tol)
    {
        for(int y:x.second){
            ans[y]=x.first;
        }
    }
    for(int x:ans) cout<<x;
}