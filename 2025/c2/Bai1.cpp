#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,ans=0;
    cin>>n;
    while (n>1)
    {
        cout<<n<<':';
        if(n%2!=0){
            ans++;
            if(((n+1)/2)%2==0)n++;
            else if(((n-1)/2)%2==0)n--;
        }
        ans++;
        n/=2;
    }
    cout<<ans;
}