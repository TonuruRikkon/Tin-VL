#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tol=0;
    string str;
    cin>>str;
    for(char x:str){
        tol+=x-'0';
    }
    cout<<tol;
}