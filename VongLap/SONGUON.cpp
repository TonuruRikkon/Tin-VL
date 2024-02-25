#include <bits/stdc++.h>
using namespace std;

int TachSo(int n)
{
    int s=0;
    while(n!=0){
        s=s+n%10;
        n=n/10;
    }
    if(s>=10) n=s;
    return s;
}

int main()
{
    int n,check=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i+TachSo(i)==n){
            cout<<i;
            break;
            check = 1;
        }
    }
    if(check==0) cout<<-1;
}