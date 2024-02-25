#include <bits/stdc++.h>
using namespace std;

int nen(int n)
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
    int n;
    cin>>n;
    while(nen(n)>=10){
        n=nen(n);
    }
    cout<<nen(n);
}