#include <bits/stdc++.h>
using namespace std;

int m,n,k;
vector<vector<int>> inp(201,vector<int>(int(201))),tol(201,vector<int>(201,0));

bool can_buy(int s)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = i; x <= m; x++)
            {
                for (int y = j; y <= n; y++)
                {
                    int tol_cost = tol[x][y] - tol[i-1][y] - tol[x][j-1] + tol[i-1][j-1]; 
                    int ans= (x-i+1)*(y-j+1);
                    if(tol_cost<=k&&ans>=s) return true; 
                }  
            }
        }
    }    
    return false;
}

int ong_phu_nhiphan(){
    int L=1, R=m*n;
    int ans=0;

    while (L<=R)
    {
        int mid=L+(R-L)/2;
        if(can_buy(mid)){
            ans = mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    return ans;
}

int main()
{
    cin>>m>>n;
    cin>>k;
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
    cout<<ong_phu_nhiphan();
}