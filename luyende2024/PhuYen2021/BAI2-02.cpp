#include <bits/stdc++.h>
using namespace std;

int dx[4]{-1,1,0,0};
int dy[4]{0,0,-1,1};
bool vis[int(1e7)][int(1e7)];
vector<string> inp;

void dfs(int x,int y)
{
    vis[x][y]=true;
    for (int i = 0; i < 4; i++)
    {
        int crtX=x+dx[i];
        int crtY=y+dy[i];
        if(inp[crtX][crtY]=='x') dfs(crtX,crtY);
    }
    
}

int main()
{
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT", "w",stdout);
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
                dfs(i,j);
                ans++;
            }
        }
    }
}