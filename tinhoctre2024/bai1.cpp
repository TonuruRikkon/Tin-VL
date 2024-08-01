#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tol=0,t=0,ans=0;
    cin>>n;
    map<int,int> a;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[x]++;

    }
    for(auto i:a){
        num.push_back(i.second);
        tol+=i.second;
        t++;
    }
    for (int i = 0; i < t; i++)
    {
        tol-=num[i];
        ans+=num[i]*tol;
    }
    cout<<ans;
    
}