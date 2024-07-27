#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,check=0;
    cin>>n;
    string ans;
    map<string,int> d;
    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin>>x>>y;
        d[x]+=y;
    }
    for(auto i:d){
        if(i.second>check){
            check=i.second;
            ans=i.first;
        }
    }
    cout<<ans;
}