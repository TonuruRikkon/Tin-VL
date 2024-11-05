#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a;
    cin>>n>>a;
    long long un=1+(n-1)*a;
    cout<<((un+1)*n)/2;
}