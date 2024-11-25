#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> inp[int(1e6)+1];
bool visited[int(1e6)];
int cost[int(1e6)+1];

int minE()
{
    
}

void prim()
{

}

int main()
{
    vector<int> tram;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        tram.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        inp[x].push_back({c,y});
        inp[y].push_back({c,x});
    }
    
}