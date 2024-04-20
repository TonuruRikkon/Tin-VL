#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;
    string str, str_2;
    getline(cin, str_2);
    getline(cin, str);
    while (str.find(str_2)!=-1)
    {
        str.erase(str.find(str_2),1);
        n++;
    }
    cout<<n;
}