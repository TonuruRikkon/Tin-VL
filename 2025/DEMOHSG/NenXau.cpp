#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int sz=str.size();
    char ref=str[0];
    int d=1;
    vector<pair<char,int>> cnt;
    for (int i = 1; i < sz; i++)
    {
        if(str[i]==ref) d++;
        else{
            cnt.push_back({ref,d});
            d=1;
        }
        ref=str[i];
    }
    cnt.push_back({ref,d});
    for(pair<char,int> x:cnt){
        cout<<x.second<<x.first;
    }
    
}