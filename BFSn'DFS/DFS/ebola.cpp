#include <bits/stdc++.h>
using namespace std;

int n,k,d=0;
bool visited[int(1e5)+1];
map<int,vector<int>> a;
vector<int> ans;

void dfs(int s)
{
    visited[s]=true;
    ans.push_back(s);
    d++;
    for(int y:a[s]){
        if(!visited[y]){
            dfs(y);
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin>>y;
            a[i].push_back(y);
        }
        
    }
    dfs(k);
    cout<<d<<endl;
    for(int x:ans) cout<<x<<" ";
}