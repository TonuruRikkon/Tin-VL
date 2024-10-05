#include <bits/stdc++.h>
using namespace std;

int m,n,ans=0;
vector<vector<int>> dao(1000,vector<int>(1000, 0));
vector<vector<bool>> visited(1000,vector<bool>(1000, false));
int dRow[4] = {0,0,-1,1};
int dCol[4] = {-1,1,0,0};

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int u = x + dRow[i];
        int v = y + dCol[i];
        if(u>=0&&u<n &&
            v>=0&&v<m &&
            dao[u][v]==1&&!visited[u][v])
            dfs(u,v);
    }
}

int main()
{
    cin>>m>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>dao[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(dao[i][j]==1&&!visited[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
        
    }
    cout<<ans;
}