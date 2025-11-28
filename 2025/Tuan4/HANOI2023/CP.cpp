#include <bits/stdc++.h>
using namespace std;


int MAXN=1e6;
vector<bool> IsNto(MAXN+1,true);

void sangnt()
{
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= MAXN; i++)
    {
        if(IsNto[i]){
            for (int j = i*i; j <= MAXN; j+=i)
            {
                IsNto[j]=false;
            }
            
        }
    }
    
}


int main()
{
    int l,r;
    cin>>l>>r;
    sangnt();
    int ans=0;
    for (int i = l; i*i <= r; i++)
    {
        if(IsNto[i]) ans++;
    }
    cout<<ans;
}