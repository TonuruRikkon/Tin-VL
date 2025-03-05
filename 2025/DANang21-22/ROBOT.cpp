#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string act;
    cin>>act;
    for(char i:act){
        if(i=='R'){
            char temp=s[s.length()-1];
            s.pop_back();
            s=temp+s;
        }
        else if(i=='L'){
            char temp=s[0];
            s.erase(s.begin());
            s=s+temp;
        }
    }
    cout<<s;
}