#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,check=0;
    cin>>n;
    string ans;
    map<string,int> a;
    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin>>x>>y;
        a[x]+=y;
    }
    for(auto i:a){
        if(i.second>check){
            check=i.second;
            ans=i.first;  
        }
    }
    cout<<ans;
}