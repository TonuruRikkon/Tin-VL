#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    int rem=n%4;
    
    if(n==3) {
        cout<<2;
        return 0;
    }
    int ans=1;
    if(rem==3) n++;
    else if(rem==1) n--;
    else ans--;
    ans+=log2(n);
    cout<<ans;
    
}