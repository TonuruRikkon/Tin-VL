#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t,s;
    cin>>t>>s;
    map<char,int> a,b;
    vector<int> ans;
    for (int i = 0; i <= t.size(); i++)
    {
        if(t[i]=='5') t[i]='2';
        if(t[i]=='9') t[i]='6';
        a[t[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='5') s[i]='2';
        if(s[i]=='9') s[i]='6';
        b[s[i]]++;
    }
    for(auto x:b){
        int y;
        y=a[x.first]/x.second;
        ans.push_back(y);
    }
    cout<<*min_element(ans.begin(),ans.end());
}