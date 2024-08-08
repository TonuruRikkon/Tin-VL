#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,tol=0,ans=0;
    cin>>k;
    map<int,int> a;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        a[x]++;
        tol++;
    }
    for(auto i:a){
        tol-=i.second;
        ans+=i.second*tol;
    }
    cout<<ans;
}