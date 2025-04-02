#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n,k,p;
    cin >> n>>k>>p;
    long long x=n/(k+1);
    cout<<(x*k+n-(x*(k+1)))*p;
}