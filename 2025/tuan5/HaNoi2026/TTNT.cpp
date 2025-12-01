#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X,S,T;
    cin>>X>>S>>T;
    int sum=X+S;
    int temp=T%sum;
    if(temp<=X&&temp!=0) cout<<1;
    else cout<<0;
}