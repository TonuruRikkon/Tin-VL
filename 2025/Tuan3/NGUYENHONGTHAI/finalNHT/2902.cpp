#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> ch(n);
    for (int i = 0; i < n; i++)
    {
        cin>>ch[i];
    }
    sort(ch.begin(),ch.end());
    vector<int> yc(m);
    for (int i = 0; i < m; i++)
    {
        cin>>yc[i];
    }
    sort(yc.begin(),yc.end());
    int l=0,r=0,ans=0;
    while (l<n&&r<m)
    {
        if(abs(ch[l]-yc[r])<=k){
            l++;
            r++;
            ans++;
        }
        else if(ch[l]<yc[r]-k&&l<n){
            l++;
        }
        else if(ch[l]>yc[r]+k&&r<m){
            r++;
        }
    }
    
    cout<<ans;
}