#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,tol=0,Pos=0,Neg=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        if(x>=0) {
            tol+=x-1;
            Pos++;
        }
        else {
            tol+=-1-x;
            Neg++;
        }
    }
    if(Neg & 1 ==0) cout<<tol;
    else{
        cout<<tol+2;
    }

}