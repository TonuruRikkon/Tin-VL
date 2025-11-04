#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<bool> visited, vector<int> )
{
    queue<int> q;
    q.push(s);

}

int main()
{
    int n,k,s;
    cin>>n>>k>>s;
    vector<vector<int>> inp(n+1); 
    vector<vector<int>> path(n+1,vector<int>(n+1));
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        inp[x].push_back(y);
        inp[y].push_back(x);
        path[min(x,y)][max(x,y)]=z;
    }
    


}