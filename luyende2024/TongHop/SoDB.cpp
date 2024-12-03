#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7),true);
vector<int> ngt;

void sangnt()
{
    fill(ngto.begin(),ngto.end(),true);
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<=int(1e6)){
        ngt.push_back(p);
        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

bool dacbiet(int n)
{
    string str=to_string(n);
    int tol=0,mul=0;
    for(char x:str){
        tol+=x-'0';
    }
    int u=n;
    for(int x:ngt){
        while(u%x==0) 
        {
            string u_str=to_string(x);
            int u_tol=0;
            for(char x:u_str){
                u_tol+=x-'0';
            }
            if(x<10){
                mul+=x;
                u/=x;                
            }
            else{
                mul+=u_tol;
                u/=x;

            }
        }
    }
    if(u>1){
        string u_str=to_string(u);
        for(char x:u_str){
            mul+=x-'0';
        }
    }
    if(tol==mul) return true;
    else return false;
}

bool nt(int s)
{
    for(int x:ngt){
        if(s==x) return true;
        else if(s%x==0) return false;
    }
    return true;
}

int main()
{
    sangnt();
    int n;
    cin>>n;
    for (long long i = n+1; i > 0; i++)
    {
        if(dacbiet(i)==true&&nt(i)==false){
            cout<<i;
            return 0;
        }
    }
    
}