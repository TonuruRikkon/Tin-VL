#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n[1000],d=1,t=0;
    char a[1000];
    string str;
    getline(cin, str);
    for(int i=0;i<=str.size()-1;i++){
        if(str[i]==str[i+1]){
            d++;
        }
        else{
            t++;
            n[t] = d;
            a[t] = str[i];
            d=1;
        }
    }
    for(int i=0; i<=t ;i++){
        if(a[i]>1) cout<<n[i]<<a[i];
        else cout<<a[i];
    }
}