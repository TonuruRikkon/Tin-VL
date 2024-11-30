#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> inp(n+1,vector<int>(n+1,0));
    vector<vector<int>> tol(n+1,vector<int>(n+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>inp[i][j];
            tol[i][j]=inp[i][j]+tol[i-1][j]+tol[i][j-1]-tol[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p1=tol[i][j]
        }
        
    }
    
}