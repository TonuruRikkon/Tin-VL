#include <bits/stdc++.h>
using namespace std;
bool check(string s,int L,int R){
    for (int i = L; i <= (L+R)/2; i++)
    {
        if(s[i]!=s[L+R-i]) return false;
    }
    return true;
}
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
        cout<<i.first<<" "<<i.second<<"!"<<endl;
    }
    for(auto i:test){
        if(check(s,i.first,i.second)==true) cout<<1<<endl;
        else cout<<-1<<endl;
    }
}