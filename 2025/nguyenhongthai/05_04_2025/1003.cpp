#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tol=0;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin>>x;
        tol+=x;
    }
    cout<<ceil(tol/6);
}