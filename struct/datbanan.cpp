#include <bits/stdc++.h>
using namespace std;

struct datbanan
{
    int song,sotien,bansize;
}a[1000+1];

int main()
{
    int n,k,d,tol;
    vector<pair<int,int>> ans;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].song>>a[i].sotien;
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>a[i].bansize;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(a[j].bansize>=a[i].song){
                ans.push_back(make_pair(i,j));
                d++;
                tol+=a[i].sotien;
            }
        }
        
    }
    cout<<d<<" "<<tol<<endl;
    for (int i = 0; i < d; i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
}