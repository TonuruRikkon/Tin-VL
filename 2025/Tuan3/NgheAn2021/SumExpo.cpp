#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long tol[2];
    memset(tol,0,sizeof(tol));
    for (int i = 2; i*i <= n; i++)
    {
        int temp=0;
        while (n%i==0)
        {
            temp++;
            n/=i;
        }
        tol[temp&1]+=temp;
    }
    if(n>1) tol[n&1]++;
    cout<<tol[0]<<'\n'<<tol[1];
}