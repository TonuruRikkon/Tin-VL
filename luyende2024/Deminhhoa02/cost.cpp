#include <bits/stdc++.h>
using namespace std;

bool visited[int(1e6)];
int wei[int(1e6)][int(1e6)];

struct diem
{
    int x,y,w;
};

vector<diem> inp[int(1e6)];

void dfs(int s)
{
    int u=s;
    for(auto v:inp[u]){

    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> t;
    memset(visited,false,sizeof(visited));
    memset(wei,0,sizeof(wei));
    for (int i = 0; i < n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        inp[x].push_back({x,y,w});
        inp[y].push_back({x,y,w});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        t.push_back(x);
    }
}