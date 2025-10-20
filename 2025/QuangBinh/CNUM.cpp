#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("C:\\code\\Tin-VL\\2025\\QuangBinh\\CNUM.INP","r", stdin);
    freopen("C:\\code\\Tin-VL\\2025\\QuangBinh\\CNUM.OUT","w", stdout);
    string inp;
    int ans=0;
    getline(cin,inp);
    for(char x:inp){
        if(x!=' ') ans++; 
    }
    cout<<ans;
}