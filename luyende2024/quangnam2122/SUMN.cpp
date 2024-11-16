#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("SUMN.INP","r",stdin);
    freopen("SUMN.OUT","w",stdout);
    int tol=0;
    string str;
    cin>>str;
    for(char x:str){
        tol+=x-'0';
    }
    cout<<tol;
}