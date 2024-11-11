#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,d,k,ans=0;
    cin>>m>>n>>d>>k;
    char x[m+1][n+1];
    int Ox[8]={0,1,1,1,0,-1,-1,-1},Oy[8]={1,1,0,-1,-1,-1,0,1};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>x[i][j];
        }    
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(x[i][j]=='P'){
                int check=0;
                for (int e = 0; e < 8; e++)
                {
                    if(x[i+Oy[e]][j+Ox[e]]=='M') check++;
                }
                if(check>=2) ans++;
            }
        }    
    }
    cout<<ans;
}