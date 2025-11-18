#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin>>m;
    string str;
    cin>>str;
    map<char,int> cnt;
    for(char x:str){
        cnt[x]++;
    }
    bool check=false;
    for(char x:str){
        if(cnt[x]==1){
            if(x+m>'z'){
                cout<<char(x+m-'z'+'a'-1);
            }
            else{
                cout<<char(x+m);
            }
            check=true;
        }
    }
    if(check==false) cout<<0;
}