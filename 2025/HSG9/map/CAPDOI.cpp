#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> pos;
    vector<int> inp;
    int n,x,ans=0;
    cin>>n>>x;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin>>q;
        pos[q]++;
    }   
    for (int i = 0; i <= ceil(float(x)/2); i++)
    {
        if(x-i==i) ans+=(pos[i]*(pos[i]-1))/2;
        else ans+=pos[i]*pos[x-i];
    }
    cout<<ans;
}