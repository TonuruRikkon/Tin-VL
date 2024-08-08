#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=n,ans=0;
    map<int,int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(auto i:a){
        k-=i.second;
        ans+=i.second*k;
    }
    cout<<ans;
}