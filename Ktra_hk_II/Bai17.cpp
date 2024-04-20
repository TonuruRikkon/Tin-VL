#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000],d=0,n=0;
    string str,temp="",chu[1000];
    memset(a,0,sizeof(a));
    memset(chu,0,sizeof(chu));
    getline(cin, str);
    for(int i=0; i<str.size(); i++){
        if(str[i]!=' '){
            temp+=str[i];
            d++;
        }
        else{
            chu[n]= temp;
            a[n] = d;
            temp = "";
            d=0;
            n++;
        }
    }
    cout<<chu[max_element(a,a+0+1000)-a];
}