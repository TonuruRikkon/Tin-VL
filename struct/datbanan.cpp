#include <bits/stdc++.h>
using namespace std;

struct datbanan
{
    int song,sotien,stt;
}a[1000+1];

bool sxsotien(datbanan a, datbanan b)
{
    return a.sotien>b.sotien;
}

int main()
{
    freopen("inputfile/datbanan.inp", "r", stdin);
    freopen("outputfile/datbanan.out", "w", stdout);
    int n,k,d=0,tol=0;
    vector<pair<int,int>> bansize;
    vector<pair<int,int>> ans;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].song>>a[i].sotien;
        a[i].stt=i+1;
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        bansize.push_back(make_pair(x,i+1));
    }
    sort(a, a+n,sxsotien);
    sort(bansize.begin(),bansize.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(bansize[j].first>=a[i].song){
                ans.push_back(make_pair(a[i].stt,bansize[j].second));
                d++;
                tol+=a[i].sotien;
                bansize[j].first=0;
                break;
                
            }
        }
        
    }
    cout<<d<<" "<<tol<<endl;
    for (int i = 0; i < d; i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
}