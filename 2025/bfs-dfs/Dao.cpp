#include <bits/stdc++.h>
using namespace std;

int as[3]={0,-1,1};

void dfs(int x, int y,vector<vector<int>> &visit){
    visit[x][y]=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(visit[x+as[i]][y+as[j]]==1){
                dfs(x+as[i],y+as[j],visit);
            }
        }
        
    }
    
}

int main()
{
    int m,n,ans=0;
    cin>>m>>n;
    vector<vector<int>> inp(m+2,vector<int>(n+2,0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin>>x;
            inp[i][j]=x;
        }   
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(inp[i][j]==1){
                dfs(i,j,inp);
                ans++;
            }
        }   
    }
    cout<<ans;
}