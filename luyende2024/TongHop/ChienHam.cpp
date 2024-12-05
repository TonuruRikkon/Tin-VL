#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis(int(1e6),vector<bool>(int(1e6),false));
int Ox[4]={0,0,1,-1};
int Oy[4]={1,-1,0,0,};
vector<vector<int>> inp(int(1e6),vector<int>(int(1e6)));
int n,m;

void dfs(int y,int x)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        if(x+Ox[i]>=0&&x+Ox[i]<m&&y+Oy[i]>=0&&y+Oy[i]<n){
            int posX=x+Ox[i];
            int posY=y+Oy[i];
            if(vis[posY][posX]==false&&inp[posY][posX]=='1'){
                dfs(posY,posX);
            }
        }
    }
}

int main()
{
    freopen("CHIENHAM.INP","r",stdin);
    freopen("CHIENHAM.OUT","w",stdout);
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin>>x;
            inp[i][j]=x;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
}
