#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,a,b,ans=0;
    cin>>k>>a>>b;
    for (int i = a; i <= b; i++)
    {
        int x=i;
        for (int j = k; j >= 2; j--)
        {
            while(x%j==0){
                    x=x/j;
            }
        }
        if(x==1){
            ans++;
        }
    }
    cout<<ans;
}