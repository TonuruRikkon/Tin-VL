#include <bits/stdc++.h>
using namespace std;

bool PDS(int s)
{
    string str=to_string(s);
    int tol=0,poww=1;
    for(char x:str){
        if(x=='0') return true;
        tol+=x-'0';
        poww*=x-'0';
    }
    if(poww%tol==0) return true;
    else return false;
}
int sangPDS(int n)
{
    int d=0;
    for (int i = 1; i < int(1e9); i++)
    {
        if(PDS(i)==true){
            d++;
        }
        if(d==n) return i;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<sangPDS(n);
}