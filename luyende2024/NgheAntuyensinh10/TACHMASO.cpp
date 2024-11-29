#include <bits/stdc++.h>
using namespace std;

int giatri(string s)
{
    int i=0,ans=0;
    while (s[i]=='0')
    {
        i++;
    }
    for (i; i < s.size(); i++)
    {
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main()
{
    vector<pair<int,string>> ans;
    string str,temp="";
    cin>>str;
    for (int i = 0; i < str.size(); i++)
    {
        if(isdigit(str[i])==true){
            temp+= str[i];
        }
        else if(temp.empty()==false){
            ans.push_back({giatri(temp),temp});
            temp="";
        }
    }
    if(temp.empty()==false){
        ans.push_back({giatri(temp),temp});
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x.second<<" ";
    }
}