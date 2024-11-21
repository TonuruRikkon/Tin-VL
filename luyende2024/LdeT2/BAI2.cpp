#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool am=false;
    int n,k,temp=0,ans=0;
    cin>>n;
    cin.ignore();
    string str;
    map<int,int> tol;
    getline(cin,str);
    cin>>k;
    for(char x:str){
        if(x=='-'){
            if(am==true){
                tol[0-temp]++;
            }
            else{
                tol[temp]++;  
            }
            am=true;
            temp=0;
        }
        else if(x>='0'&&x<='9'){
            temp=temp*10+(x-'0');
        }
        else{
            if(am==true){
                tol[0-temp]++;
            }
            else{
                tol[temp]++;
            }
            am=false;
            temp=0;
        }
    }
    if(am==true){
        tol[0-temp]++;
    }
    else{
        tol[temp]++;
    }
    for(auto x:tol){
        ans+=x.second*tol[k-x.first];
        tol[x.first]=0;
        tol[k-x.first]=0;
    }
    cout<<ans;
}