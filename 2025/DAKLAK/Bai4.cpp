#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    int k,ans=0;
    cin>>n>>k;
    for (long long i = 0; i <= n; i++)
    {
        long long a=i,cnt=0;
        while (a>0)
        {
            if(!(a&1)) cnt++;
            a>>=1;
        }
        if(cnt==k) {
            ans++;
        }
    }
    cout<<ans;
}