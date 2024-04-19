#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    while(str[0] == ' ') str.erase(0,1);
    while(str[str.size()-1]==' ') str.erase(str.size()-1, 1);
    cout<<"!"<<str<<"!";
}