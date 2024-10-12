#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> visited;
vector<vector<int>> moved;
int dRow[4] = {0,0,-1,1};
int dCol[4] = {-1,1,0,0};

void bfs(int x, int y)
{
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    moved[x][y]=0;
    while (!q.empty())
    {
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = f + dRow[i];
            int v = s + dCol[i];
            if(u>=0 && u<n && v>=0 && v<m && !visited[u][v] && a[u][v]==0 ) {
                q.push(make_pair(u,v));
                moved[u][v]=moved[f][s] + 1;
                visited[u][v]=true;                
            }
            else if(u>=0 && u<n && v>=0 && v<m && visited[u][v] && a[u][v]==0 ){
                if(moved[u][v]>moved[f][s] + 1){
                    q.push(make_pair(u,v));
                    moved[u][v]=moved[f][s] + 1;                    
                }
            }
        }   
        
    }
    
}

int main()
{
    cin>>m>>n;
    a.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    moved.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }     
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j]==2){
                bfs(i,j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<moved[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
} 