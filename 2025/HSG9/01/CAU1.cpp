#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,ans=0;
    cin>>x>>y;
    int top=__gcd(x,y);
    for (int i = 1; i <= sqrt(top); i++)
    {
        if(top%i==0){
            ans++;
            if(top/i!=i){
                ans++;
            }
        }
    }
    cout<<ans;
}
