#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans;
    string str;
    cin>>str;
    for(char i:str){
        if(i>='A'&&i<='O'){
        }
        else if(i>='P'&i<='S'){
            ans+=7+1;
            cout<<7+1<<"P"<<endl;
        }
        else if(i>='T'&&i<='V'){
            ans+=8+1;
            cout<<8+1<<"T"<<endl;
        }
        else if(i>='W'&i<='Z'){
            ans+=9+1;
            cout<<9+1<<"W"<<endl;
        }
    }
    cout<<ans;
}