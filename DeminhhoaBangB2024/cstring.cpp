#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int sizeo=str1.size(),j=0,d=0;
    if(str2.size()>int(1e3)){
        for(char x:str2){
            if(x==str1[j]){
                j++;
            }
            if(j==sizeo){
                d++;
                j=0;
            }
        }
    }
    else{
        while(str2.find(str1)!=-1){
            str2.erase(str2.find(str1),str1.size());
        }
    }
    cout<<d;
}