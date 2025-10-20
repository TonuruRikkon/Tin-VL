#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    long long powA=1,powB=1;
    if(b>40){
        for (int i = 0; i < (b%40)+40; i++)
        {
            powA*=a;
        }
    }
    else{
        for (int i = 0; i < b%40; i++)
        {
            powA*=a;
        }
    }

    if(a>40){
        for (int i = 0; i < (a%40)+40; i++)
        {
            powB*=b;
        }
    }
    else{
        for (int i = 0; i < a%40; i++)
        {
            powB*=b;
        }
    }
    
    // int ans=(powA+powB)%100;
    // if(ans<10) cout<<0<<ans;
    // else cout<<ans;

    cout<<powA<<' '<<powB;

}