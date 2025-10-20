#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> mp;
    for (int i = 0; i < n; i++)
    {
        string inp;
        cin>>inp;
        mp[inp]++;
    }
    for (int i = 0; i < n-1; i++)
    {
        string inp;
        cin>>inp;
        mp.erase(inp);
    }
    cout<<mp.begin()->first;
}