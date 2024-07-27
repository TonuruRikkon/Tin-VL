#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    map<int,int> cap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cap[x]++;
    }
    for (int i = 0; i <= k/2; i++)
    {
        if(k-i==i)ans+=(i)/2;
        else ans+=cap[i]*cap[k-i];
    }
    cout<<ans;
}