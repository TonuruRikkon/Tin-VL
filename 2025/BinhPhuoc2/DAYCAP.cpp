#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k,maxx=INT_MIN;
    cin>>n>>k;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        maxx=max(maxx,x);
    }
    int ans=0,l=1,r=maxx;

    while (l<r)
    {
        int mid=l+(r-l)/2;
        int cnt=0;
        for(int x:inp){
            cnt+=x/mid;
        }
        if(cnt>=k) l=mid;
        else if(cnt<k) r=mid-1;
        if(cnt==k) ans=mid;
    }
    
    cout<<ans;
}