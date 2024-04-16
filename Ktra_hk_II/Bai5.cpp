#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d[256],ans=0;
    string str;
    getline(cin, str);
    memset(d,0,sizeof(d));
    for(int i=0; i<str.size(); i++){
        d[str[i]]++;
    }
    for(int i=0; i <256; i++){
        if(d[i]!=0) ans++;
    }
    cout<<ans;
}