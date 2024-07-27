#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,check=0;
    cin>>n>>k;
    string str,ans;
    cin>>str;
    map<char,int> d;
    for (int i = 0; i < n; i++)
    {
        d[str[i]]++;
    }
    for (auto i:d)
    {
        if(i.second>=k) cout<<i.first;
        if(i.second>check) {
            check=i.second;
        }
    }
    for(auto i:d)
    {
        if(i.second==check)cout<<endl<<i.first<<" "<<check;
    }
    
}