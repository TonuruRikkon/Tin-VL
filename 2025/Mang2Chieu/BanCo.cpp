#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> step(n,vector<int>(m,0));
    step[0][0]=0;
    step[0][1]=step[1][0]=1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            step[i][j]=min(step[i-1][j],step[i][j-1])+1;
        }
        
    }
    cout<<step[n-1][m-1];
}