#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            ans++;
            if(n/i!=i){
                ans++;
            }
        }
    }
    cout<<ans;
}