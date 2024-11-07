#include <bits/stdc++.h>
using namespace std;

long long tonguoc[int(1e6)];

int demuocupper(int x)
{
    for (long long i = 2; i < x; i++)
    {
        if(x%i==0){
            if((x/i)<int(1e6)){
                return tonguoc[x/i]*tonguoc[i];
            }
        }
    }
    
}

void tongu()
{
    memset(tonguoc,0,sizeof(tonguoc));
    for (int i = 1; i < int(1e6); i++)
    {
        for (int j = i; j < int(1e6); j+=i)
        {
            tonguoc[j]+=i;
        }
        
    }
    
}

int main()
{
    freopen("BOMCHUM.INP","r",stdin);
    freopen("BOMCHUM.OUT","w",stdout);
    int q;
    cin>>q;
    tongu();
    for (int i = 0; i < q; i++)
    {
        int x,ans=0;
        cin>>x;
        if(x<int(1e6)) cout<<tonguoc[x]<<" ";
        else{
            if((x%10)%2==0&&x%10!=5){
                cout<<x+1<<" ";
            }
            else{
                cout<<demuocupper(x)<<" ";
            }
        }
    }
    
}