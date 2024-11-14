#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)];

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<int(1e7)){
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<int(1e7)&&ngto[p]==false;p++);
    }
    
}

bool tonguoc(int s)
{
    int n=s;
    long long tol=0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            if(n/i==i) tol+=i;
            else tol+=i+n/i;
        }
    }
    if(ngto[tol]==true) {
        cout<<s<<" "<<tol<<endl;
        return true;
    }
    else return false;
}

int main()
{
    int n,toln=0;
    cin>>n;
    sangnt();
    for (int i = 1; i <= n; i++)
    {
        if(tonguoc(i)==true) toln++;
    }
    cout<<endl;
    cout<<toln<<endl<<ngto[289];
}