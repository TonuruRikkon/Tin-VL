#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        ans+=x/k;
    }
    cout<<ans;
}