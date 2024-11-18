#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    string s,t;
    cin>>s>>t;
    while (t.find(s)!=-1)
    {
        ans++;
        t.erase(0,t.find(s)+1);
    }
    cout<<ans;
    
}