#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for(int i=0;i<=str.size()-1; i++){
        if(str[i]=='a') str[i]='z';
        else str[i] -= 1;
    }
    cout<<str;
}