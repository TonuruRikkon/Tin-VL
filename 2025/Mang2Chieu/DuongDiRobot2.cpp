#include <bits/stdc++.h>
using namespace std;

int bfs(int x, int y,int tol,vector<vector<int>>inp)
{
    queue<pair<int,int>> doi;
    doi.push({x,y});
    tol+=inp[x][y];
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> inp;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        inp.emplace_back(temp);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            inp[i].emplace_back(x);
        }
    }

    
}