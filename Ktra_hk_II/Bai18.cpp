#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,chu[256];
    memset(chu,0,sizeof(chu));
    string str;
    getline(cin,str);
    /*doi chu hoa thanh chu thuong*/
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z'){
            str[i]-= 'a'-'A';
        }
    }
    for(int i=0; i<str.size(); i++){
        chu[str[i]]+=1;
    }
    for(int i=0; i<=256;i++){
        if(chu[i]==1)cout<<char(i)<<endl;
    }
}