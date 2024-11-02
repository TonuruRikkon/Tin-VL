#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    char ref='*';
    cin>>str;
    int d=1;
    vector<pair<int,char>> ans;
    for(char x:str){
        if(x!=ref){
            if(ref!='*')
            ans.push_back(make_pair(d,ref));
            ref=x;
            d=1;
        }
        else{
            d++;
        }
    }
    ans.push_back(make_pair(d,ref));
    for(auto x:ans){
        if(x.first!=1)
        cout<<x.first<<x.second;
        else{
            cout<<x.second;
        }
    }
}