#include<bits/stdc++.h>
using namespace std;

int main()
{
    int long long a[100000],n,ans=0;
    map<int long long,long long> d;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        d[a[i]++];
    }
    for(auto&i:d){
        cout<<((i.second)+(i.second-1)/2)<<endl;
        ans+=((i.second)+(i.second-1))/2;
    }
    cout<<ans;
}