#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> inp(n+1,vector<int>(n+1,0));
    vector<vector<int>> tol(n+1,vector<int>(n+1,0));
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>inp[i][j];
            tol[i][j]=inp[i][j]+tol[i-1][j]+tol[i][j-1]-tol[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vector<int> p(4);
            int p1=p[0]=tol[i][j];
            int p2=p[1]=tol[n][j]-p1;
            int p3=p[2]=tol[i][n]-p1;
            int p4=p[3]=tol[n][n]-p1-p2-p3;
            int minn=*min_element(p.begin(),p.end());
            ans.push_back({count(p.begin(),p.end(),minn),minn});
        }
    }
    cout<<ans[max_element(ans.begin(),ans.end())-ans.begin()].second;
}