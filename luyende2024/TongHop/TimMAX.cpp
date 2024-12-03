#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,d=0;
    long long tol=1;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        tol*=i;
        while(tol%m==0){
            tol/=m;
            d++;
        }
    }
    cout<<d;
}