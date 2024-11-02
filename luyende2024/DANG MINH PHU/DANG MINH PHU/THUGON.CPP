#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("THUGON.INP","r",stdin);
    freopen("THUGON.OUT","w",stdout);
    int d=1;
    string str;
    char ref='*';
    cin>>str;
    vector<pair<int,char>> ans;
    for(char x:str){
        if(ref!=x){
            ans.push_back(make_pair(d,ref));
            d=1;
            ref=x;
        }
        else{
            d++;
        }
    }
    ans.push_back(make_pair(d,ref));
    for (int i = 1; i < ans.size(); i++)
    {
        if(ans[i].first==1){
            cout<<ans[i].second;
        }
        else{
            cout<<ans[i].first<<ans[i].second;
        }
    }

}
