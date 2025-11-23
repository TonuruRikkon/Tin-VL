#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    map<string,int> inp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        if(inp[str]!=0) cout<<str<<inp[str];
        else cout<<str;
        inp[str]++;
        cout<<'\n';
    }
    
}