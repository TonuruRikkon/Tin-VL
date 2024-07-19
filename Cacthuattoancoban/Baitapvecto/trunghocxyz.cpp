#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,dem[10][10],ans;
    memset(dem,0,sizeof(dem));
    cin>>n;
    vector<int> c;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int d=1;
        while (dem[d][c[i]]!=0)
        {
            d++;
        }
        dem[d][c[i]] = i;
        d=1;
        cout<<d<<"!";
    }
    cout<<endl;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout<<dem[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
}