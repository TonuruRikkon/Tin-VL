#include <bits/stdc++.h>
using namespace std;

int dx[4]{-1,1,0,0};
int dy[4]{0,0,-1,1};
bool vis[int(256)][int(256)];
vector<string> inp;

void dfs(int x,int y,int n,int m)
{
    vis[x][y]=true;
    for (int i = 0; i < 4; i++)
    {
        int crtX=x+dx[i];
        int crtY=y+dy[i];
        if(crtX<m&&crtX>=0&&crtY<n&&crtY>=0)
        {
            if(inp[crtX][crtY]=='x'&&vis[crtX][crtY]==false){
                dfs(crtX,crtY,n,m);
            }
        }
    }
    
}

int main()
{
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT", "w",stdout);
    memset(vis,false,sizeof(vis));
    int d=0;
    inp.push_back("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    string str;
    while(cin>>str){
        inp.push_back("0"+str);
    }
    int ans=0;
    for(int i=1;i<inp.size();i++){
        for(int j=1;j<inp[i].size();j++){
            if(inp[i][j]=='x'&&vis[i][j]==false){
                dfs(i,j,inp[i].size(),inp.size());
                ans++;
            }
        }
    }
    cout<<ans;
}