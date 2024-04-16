#include <bits/stdc++.h>
using namespace std;

string rev(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string str;
    getline(cin, str);
    if(str == rev(str)) cout<<"YES";
    else cout<<"NO";
}