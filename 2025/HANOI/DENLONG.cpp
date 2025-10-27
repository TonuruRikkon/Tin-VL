#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> inp,cnt(10,0),tol;
    tol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        cnt[x]++;
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= i ; j--)
        {
            
        }
        
    }
    

}