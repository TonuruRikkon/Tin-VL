#include <bits/stdc++.h>
using namespace std;
#define MOD(x) ((x) % 1000000007)
long long n,s[1000001],a[1000001],k,p;
int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
   cout << MOD( MOD((k-1)/n * s[n]) + MOD(s[(k+p-1)%n] - s[(p%n)-1]) );
    return 0;
}