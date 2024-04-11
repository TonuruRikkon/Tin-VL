#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    str=' '+str;
    if(str.find("aa")== -1){
        cout<<"khong co";
    }
    else cout<<str.find("aa");
}