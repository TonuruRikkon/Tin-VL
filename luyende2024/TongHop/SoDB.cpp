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
        for (int i = 2; i <= int(1e6); i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

bool dacbiet(int n)
{
    string str=to_string(n);
    int tol=0,mul=1;
    for(char x:str){
        tol+=x-'0';
    }
    int u=n;
    for(int x:ngto){
        while(u%x==0) 
        {
            mul*=x;
            u/=x;
        }
    }
    if(tol==mul) return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    for (long long i = n; i > 0; i++)
    {
        if(dacbiet(i)==true){
            cout<<i;
            return 0;
        }
    }
    
}