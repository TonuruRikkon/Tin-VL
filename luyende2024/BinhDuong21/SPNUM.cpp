#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)];
vector<int> ngt;

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[1]=ngto[0]=false;
    int p=2;
    while(p*p<int(1e6)){
        ngt.push_back(p);
        for (int i = 2; i < int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);
    }
}

bool kiemtra(int s)
{
    int n=s;
    int toln=0,tolngt=0;
    string str=to_string(n);
    for(char x:str) {
        tolngt+=x-'0';
    }
    for(int x:ngt){
        if(x*x>n) break;
        while (n%x==0)
        {
            n=n/x;
            toln+=x;
        }
    }
    if(n>1){
        string ref=to_string(n);
        for(char x:ref) toln+=x-'0';
    }
    if(toln==tolngt) return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    sangnt();
    while(true)
    {
        n++;
        if(kiemtra(n)==true&&ngto[n]==false){
            cout<<n;
            break;
        }
    }
}