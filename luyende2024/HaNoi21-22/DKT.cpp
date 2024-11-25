#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long tol=n*(n+1)/2;
    cout<<char('A'+tol%('z'-'a'+1));
}