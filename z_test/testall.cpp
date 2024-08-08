#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<pair<int,int>> test;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        cin>>x>>y;
        test.push_back(make_pair(x-1,y));
    }
    for(auto i:test){
        cout<<i.first<<" "<<i.second<<"!"<<endl;
    }
    for(auto i:test){
        string a="",b="";
        a=s.substr(i.first,i.second);
        cout<<a<<endl;
    }
}