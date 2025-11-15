#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;int k;
    cin>>k;
    vector<vector<int>> inp(n,vector<int>(m,0));
    vector<vector<int>> tol(n+1,vector<int>(m+1,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>inp[i][j];
            tol[i+1][j+1]=inp[i][j]+tol[i][j+1]+tol[i+1][j]-tol[i][j];
        }
        
    }
    int ans=0;
    for (int r1 = 0; r1 <= n; r1++)
    {
        for (int r2 = r1+1; r2 <= n; r2++)
        {
            for (int c1 = 0; c1 <= m; c1++)
            {
                for (int c2 = c1+1; c2 <= m; c2++)
                {
                    int sz=(r2-r1)*(c2-c1);
                    int val=tol[r2][c2]-tol[r2][c1]-tol[r1][c2]+tol[r1][c1];
                    if(val<k) ans=max(ans,sz);
                }
                
            }
            
        }
        
    }
    
    cout<<ans;
    
}