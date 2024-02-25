#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n;
    x=sqrt((float) n);
    if(x<(int) x) y=(n/x)+1;
    else y=n/x;
    cout<<x<<" "<<y;
    
}