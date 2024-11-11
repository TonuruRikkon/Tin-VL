#include <bits/stdc++.h>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

struct diem
{
    int x,y,z;
};

bool is_valid(int inp1,int inp2,int inp3,set<pair<int,int>> visited, set<pair<int,int>> obs, int s)
{
    if(visited.find({inp1,inp2})==visited.end()){
        if(obs.find({inp1,inp2})==obs.end()){
            if(inp3<=s){
                return true;
            }
        }
    }
    return false;
}

void bfs(set<pair<int,int>>& visited, set<pair<int,int>> obs, int s)
{
    queue<diem> q;
    q.push({0,0,0});
    visited.insert({0,0});
    while(q.empty()==false)
    {
        diem current=q.front();
        q.pop();
        current.z++;
        for (int i = 0; i < 4; i++)
        {
            int nx =current.x + dx[i];
            int ny =current.y + dy[i];
            if(is_valid(nx,ny,current.z,visited,obs,s)==true){
                q.push({nx,ny,current.z});
                visited.insert({nx,ny});
            }
        }
    }
    
}

int main()
{
    int c,s;
    cin>>c>>s;
    set<pair<int,int>> obs,visited;
    for (int i = 0; i < c; i++)
    {
        int x,y;
        cin>>x>>y;
        obs.insert(make_pair(x,y));
    }
    bfs(visited,obs,s);
    cout<<visited.size();
}