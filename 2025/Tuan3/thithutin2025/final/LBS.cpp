#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("LBS.INP", "r", stdin);
    freopen("LBS.OUT", "w", stdout);
    int n,k;
    cin>>n>>k;
    string inp;
    cin>>inp;
    int d=1;
    int rem=0;
    for (int i = 0; i < n; i++)
    {
        if(inp[i]==inp[i+1]){
            d++;
        }
        else{
            int remd=d-k;
            if(remd>0) rem+=remd;
            d=1;
        }
    }
    cout<<inp.size()-rem;
    

}