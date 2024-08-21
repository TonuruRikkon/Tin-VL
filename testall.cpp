#include<bits/stdc++.h>
using namespace std;
int main(){
    int se=0;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==s[i+1]) se+=2;
        if(s[i]=='a' or s[i]=='d' or s[i]=='g' or s[i]=='j' or s[i]=='m' or s[i]=='p' or s[i]=='t' or s[i]=='w') se++;
        if(s[i]=='b' or s[i]=='e' or s[i]=='h' or s[i]=='k' or s[i]=='n' or s[i]=='q' or s[i]=='u' or s[i]=='x') se+=2;
        if(s[i]=='c' or s[i]=='f' or s[i]=='i' or s[i]=='l' or s[i]=='o' or s[i]=='r' or s[i]=='v' or s[i]=='y') se+=3;
        if(s[i]=='s' or s[i]=='z') se+=4;
        cout<<s[i]<<"."<<se<<endl;
    }cout<<se;
}