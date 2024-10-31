#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    if(b%3==0){
        int k=__gcd(a,(b/3));
        for (int i = 1; i <= sqrt(k); i++)
        {
            if(k%i==0){
                if(i==k/i){
                    ans+=i;
                }
                else{
                    ans+=i+k/i;
                }
            }
        }
    }
    cout<<ans;
}