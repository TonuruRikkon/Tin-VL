#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("TONGCHUSO.INP", "r", stdin);
    freopen("TONGCHUSO.OUT", "w", stdout);
    long long ans=0;
    string str;
    cin>>str;
    for(char s:str){
        ans+=(s-'0');
    }
    cout<<ans;
}