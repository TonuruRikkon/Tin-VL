#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string str,str2;
    getline(cin,str);
    getline(cin,str2);
    int n=str.size(),m=str2.size();
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(str[i-1]==str2[j-1]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    cout<<a[n][m];
}