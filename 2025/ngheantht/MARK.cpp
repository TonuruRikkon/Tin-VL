#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> a;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        a[str]++;
    }
    for (int i = 0; i < n-1; i++)
    {
        string str;
        cin>>str;
        a[str]++;
    }
    for(auto x:a) if(x.second==1) {
        cout<<x.first;
        break;
    }
}