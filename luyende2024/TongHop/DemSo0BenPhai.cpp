#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    unsigned long long tol=1;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        tol*=i;
    }
    cout<<tol<<"\n";
    cout<<n/5+n/25+n/125+n/625;
}