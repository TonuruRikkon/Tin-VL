#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=0;
    for (int i = 0; i < str.size(); i++)
    {
        n+=str[i]-'0';
    }
    if(n%10==9) cout<<1;
    else cout<<0;
}