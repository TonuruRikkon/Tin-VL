#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> tol(3,vector<int>(n+1,0));
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        tol[0][i+1]=tol[0][i];
        tol[1][i+1]=tol[1][i];
        tol[2][i+1]=tol[2][i];
        tol[x-1][i+1]++;
    }
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<tol[0][y]-tol[0][x-1]<<' '<<tol[1][y]-tol[1][x-1]<<' '<<tol[2][y]-tol[2][x-1]<<'\n';
    }
    
}