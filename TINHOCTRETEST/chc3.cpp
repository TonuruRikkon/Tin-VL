#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int tol=0;
    bool checking=false;
    string temp="";
    for(int i=0; i<s.size();i++){
        if(checking==false){
            if(s[i]=='0') continue;
            else checking=true;
        }
        tol+=s[i]-'0';
        temp+=s[i];
    }
    if(tol%3==0){
        if(temp.empty()==false)cout<<temp;
        else cout<<"-1";
        return 0;
    }
    else{
        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]==tol%3-'0'){
                temp.erase(i,1);
                tol-=tol%3;
                break;
            }
        }            
        while(tol%3!=0){
            bool isloop=false;
            for(int i=temp.size()-1; i>=0; i--){
                if((tol-(temp[i]-'0'))%3==0){
                    tol-=temp[i]-'0';
                    temp.erase(i,1);
                    isloop=true;
                    break;
                }
            }
            if(isloop==false){
                cout<<"-1";
                return 0;
            }
        }
        cout<<temp;
    }
    return 0;
}