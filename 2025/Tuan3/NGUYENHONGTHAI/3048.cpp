#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin>>str;
    int ans=0,ans2=0;
    bool check=false;
    char ref='.';
    for(char x:str){
        if(ref=='0'&&x=='1') {
            ans+=2;
            check=true;
        }
        ref=x;
    }
    if(str.back()=='0'&&str[0]=='1') ans++;
    if(str.back()=='1'&&str[0]=='0') ans--;
    if(check==true) cout<<ans;
    else cout<<1;
}