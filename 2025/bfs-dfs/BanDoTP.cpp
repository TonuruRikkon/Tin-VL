#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i,int j, vector<vector<int>> &inp, vector<vector<int>> &road, int n,int m)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    road[i][j]=0;
    while (q.empty()==false)
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<n&&ny<m&&nx>=0&&ny>=0){
                if(inp[nx][ny]==0&&road[nx][ny]==-1){
                    q.push({nx,ny});
                    road[nx][ny]=road[x][y]+1;
                }                
            }

        }        
    }
    

    
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> inp;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        inp.push_back(temp);
        for (int j = 0; j < m; j++)
        {
            int x;
            cin>>x;
            inp[i].push_back(x);
        }
        
    }
    vector<vector<int>> road(n,vector<int>(m,-1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(inp[i][j]==2){
                bfs(i,j,inp,road,n,m);
            }   
        }
        
    }
    
    for(vector<int> x:road){
        for(int y:x) cout<<y<<' ';
        cout<<'\n';
    }
    
}