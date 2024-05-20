#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    string str;
    cin>>str;
    for (int i = 0; i < str.size(); i++)
    {
        t+=str[i]-'0';
    }
    if(t%10==9)cout<<1;
    else cout<<0;
}