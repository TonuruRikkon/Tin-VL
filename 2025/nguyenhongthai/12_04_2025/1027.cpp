#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long tolSqr=1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        tolSqr*=4;
    }
    cout<<int((sqrt(tolSqr)+1)*(sqrt(tolSqr)+1));
}