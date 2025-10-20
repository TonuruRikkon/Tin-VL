#include <bits/stdc++.h>
using namespace std;

int as[3]={0,-1,1};

void bfs(vector<vector<int>> matrix, vector<vector<pair<int,int>>> &trace){
    vector<vector<int>> visit=matrix;
    queue<pair<int,int>> q;
    q.push({1,1});
    visit[1][1]=0;
    while(q.empty()==false){
        pair<int,int> u=q.front();
        for(int i=0;i<3;i++){
            for (int j = 0; j < 3; j++)
            {
                if(visit[u.first+as[i]][u.second+as[j]]==1){
                    q.push({u.first+as[i],u.second+as[j]});
                    visit[u.first+as[i]][u.second+as[j]]=0;
                    trace[u.first+as[i]][u.second+as[j]]=u;
                }
            }
            
        }
        q.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> inp(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin>>x;
            inp[i][j]=x;
        }
    }
    vector<vector<pair<int,int>>> trace(n+1,vector<pair<int,int>>(m+1,{-1,-1}));
    bfs(inp,trace);
    if(trace[n][m]==make_pair(-1,-1)) cout<<0;
    else cout<<1;
    
}