#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input/KLPchucai.inp", "r", stdin);
    freopen("output/KLPchucai.out", "w", stdout);
    string ro,zig;
    int ans=0;
    map<char,int> chek;
    map<char,int> chek2;
    cin>>ro>>zig;
    for(char i:ro){
        chek[i]++;
    }
    for(char i:zig){
        chek2[i]++;
    }
    for(auto i:chek){
        if(i.second<chek2[i.first]) ans=1;
    }
    if(ans==1){
        cout<<"IMPOSSIBLE";
    }
    else if(ans==0) cout<<"POSSIBLE";
}