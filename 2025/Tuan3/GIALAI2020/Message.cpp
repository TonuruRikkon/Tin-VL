#include <bits/stdc++.h>
using namespace std;

unordered_map<char,char> anhxa()
{
    unordered_map<char,char> ret;
    for (int i = 33; i <= 126; i++)
    {
        bitset<8> sett(i);
        string str=sett.to_string();
        reverse(str.begin(),str.end());
        bitset<8> ans(str);
        ret[ans.to_ulong()]=char(i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("Message.inp","r",stdin);
    freopen("Message.out","w", stdout);
    unordered_map<char,char> as=anhxa();
    string inp;
    while (getline(cin,inp))
    {
        for(char c:inp){
            if(as[c]!=0) cout<<as[c];
            else cout<<c;
        }
        cout<<'\n';
    }
    return 0;
    
    
}