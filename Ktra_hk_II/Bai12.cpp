#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for(int i=0;i<=str.size()-1; i++){
        while(str[i]==str[i+1]) str.erase(i,1);
    }
    cout<<str;
}