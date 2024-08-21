#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    string str;
    vector<pair<string,string>> a;
    for (int i = 0; i < n; i++)
    {
        string x,y;
        getline(cin, x);
        getline(cin, y);
        a.push_back(make_pair(x,y));
    }
    getline(cin,str);
    for(auto i:a){
        while(str.find(i.first)!=-1){
            str.insert(str.find(i.first),i.second);
            str.erase(str.find(i.first),size(i.first));
        }
    }
    cout<<str;
}