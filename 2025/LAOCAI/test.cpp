#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    cin>>n>>a;
    long long powN=1;
    for (int i = 0; i < a; i++)
    {
        powN*=n;
        cout<<powN<<' '<<powN%100<<'\n';
    }
    
}