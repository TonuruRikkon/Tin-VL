#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,length;
    string str;
    getline(cin,str);
    length = str.size();
    /*for(int i=0; i<=length-1;i++){
        if(str[i]=='!') str[i]='.';
    }
    for(int i=0; i<=length-1;i++){
        while(str[i]==str[i+1]&str[i]=='.') str.erase(i,1);
    }*/
    for(int i=0;i<=length-1;i++){
        while(str[i]==str[i+1]&&str[i]==str[i+2]&&str[i]=='.') str.erase(i,1);
    }
    for(int i=0;i<=length-1;i++){
        if(str[i]==str[i+1]&&str[i]=='.') 
        {
            str.insert(i,".");
            i+=2;
        };
    }
    cout<<str;
}