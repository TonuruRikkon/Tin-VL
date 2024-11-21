#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,k,ans=0;
    cin>>m>>n;
    cin>>k;
    vector<vector<int>> inp(m,vector<int>(n)),tol(m+1,vector<int>(n+1,0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>inp[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tol[i][j]=inp[i-1][j-1]+tol[i-1][j]+tol[i][j-1]-tol[i-1][j-1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x <= i; x++)
            {
                for (int y = 1; y <= j; y++)
                {
                    if(tol[i][j]-tol[x][y]<=k){
                        ans=max(ans,(i-x+1)*(j-y+1));
                    }
                }   
            }
        }
    }
    cout<<ans;
}