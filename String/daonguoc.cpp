#include <bits/stdc++.h>
using namespace std;

string str;
int lenght;

string reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    getline(cin,str);
    cout<<reverse(str);
}

