#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long tong=0,ans=0;
    vector<int> a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        tong+=x;
    }
    for(int x:a){
        tong-=x;
        ans+=x*tong;
    }
    cout<<ans;
}