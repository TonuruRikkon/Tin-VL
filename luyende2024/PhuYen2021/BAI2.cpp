#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT", "w",stdout);
    int d=0;
    vector<string> inp;
    inp.push_back("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    string str;
    while(cin>>str){
        inp.push_back("0"+str);
    }
    for (int i = 0; i < inp.size(); i++)
    {
        for(int j=0;j<inp[i].size();j++){
            if(inp[i][j]=='x'){
                if(inp[i-1][j]=='x'||inp[i][j-1]=='x') continue;
                else{
                    d++;
                }
            }
        }
    }
    cout<<d;
}