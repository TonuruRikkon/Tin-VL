#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int sizeo=str1.size(),j=0,d=0;
    for(char x:str2){
        if(x==str1[j]){
            j++;
        }
        if(j==sizeo){
            d++;
            j=0;
        }
    }
    cout<<d;
}