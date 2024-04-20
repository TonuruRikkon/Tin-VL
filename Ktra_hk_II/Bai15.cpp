#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;
    string str, str_2;
    getline(cin, str);
    getline(cin, str_2);
    while (str_2.find(str)!=-1)
    {
        str_2.erase(str_2.find(str),1);
        n++;
    }
    cout<<n;
}