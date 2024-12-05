#include<bits/stdc++.h>
using namespace std;

bool doixung(string str)
{
    string temp=str;
    reverse(temp.begin(),temp.end());
    if(temp==str) return true;
    else return false;
}

int main()
{
    int ans=0;
    string str;
    cin>>str;
    while (doixung(str)==true)
    {
        if(str.size()==1) break;
        ans++;
        str=str.substr(0,str.size()/2);
    }
    cout<<ans;
}