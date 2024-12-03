#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    str.assign(10,'a');
    int d=0;
    for(char x:str) cout<<x<<++d;
    cout<<"\n";
    str.assign(5,'b');
    d=0;
    for(char x:str) cout<<x<<++d;
}