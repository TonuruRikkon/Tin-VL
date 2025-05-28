#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<string> a;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        a.insert(str);
    }
    for (int i = 0; i < n-1; i++)
    {
        string str;
        cin>>str;
        a.erase(str);
    }
    for(string x:a) cout<<x;
}