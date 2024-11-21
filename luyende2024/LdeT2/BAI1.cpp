#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,a,b,ans=0;
    cin>>k>>a>>b;
    for(int i=a;i<=b;i++){
        int u=i;
        for (int j = 2; j <= k; j++){
            while (u%j==0)
            {
                u/=j;
            }
        }
        if(u==1&&u!=i) ans++;
    }
    cout<<ans;
}
