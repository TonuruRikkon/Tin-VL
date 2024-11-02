#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("SODEP.INP","r",stdin);
    freopen("SODEP.OUT", "w", stdout);
    string str;
    cin>>str;
    int T=0;
    for (int i = 0; i < str.size(); i++)
    {
        T+=str[i]-'0';
    }
    if(T%10==9) cout<<1;
    else cout<<0;
}