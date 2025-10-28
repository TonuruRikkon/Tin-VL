#include <bits/stdc++.h>
using namespace std;

void tongu(vector<int> &toguc)
{

    //O((n^2)/2) quá tốn dữ liệu
    for (int i = 1; i <= int(1e6); i++)
    {
        for (int j = i; j <= int(1e6); j+=i)
        {
            toguc[j]+=i;
        }
        
    }
    // O(sqrt(n)*n/2)
    //
    // for (int i = 0; i*i <= int(1e6); i++)
    // {
    //     if(ngto[i]==true)
    //     for (int j = i*i; j <= int(1e6); j++)
    //     {
    //         **DIEU KIEN**
    //     }
    //
    // }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> toguc(int(1e6)+1,0);
    tongu(toguc);
    int ans=0;
    for (int i = n; i <= m; i++)
    {
        if(2*i<toguc[i]) ans++;
    }
    cout<<ans;
    
}