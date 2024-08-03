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
        test.push_back(make_pair(x-1,y-1));
    }
    for(auto i:test){
        string a,b;
        a=s.substr(i.first,i.second);
        b=a;
        reverse(a.begin(),a.end());
        if(a==b)cout<<1<<endl;
        else cout<<-1<<endl;
    }
}