#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d=0;
    string str, str2;
    getline(cin, str);
    getline(cin,str2);
    if(str2.find(str)!=-1){
        while (str2.find(str)!=-1)
        {
            str2.erase(str2.find(str),str.length());
            d++;
        }
        if(str2=="") cout<<d;
        else cout<<0;
    }
    else cout<<0;
}