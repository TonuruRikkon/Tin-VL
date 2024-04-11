#include <bits/stdc++.h>
using namespace std;

string reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
}


int main()
{
    string str,str_rev;
    getline(cin,str);
    cout<<str.find(",")<<endl;
    str_rev = reverse(str);
    cout<<str_rev.find(",")<<endl;
}