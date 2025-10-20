#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("InBq.txt", "R" ,stdin);
    freopen("OutB1.txt", "W", stdout);
    int n;
    cin>>n;
    vector<vector<int>> ans(n+1,vector<int>(n+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i*j<2*n)
            ans[i][j]=i*j;
            
        }
        
    }
    

}