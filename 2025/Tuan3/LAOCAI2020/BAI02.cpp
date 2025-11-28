#include <bits/stdc++.h>
using namespace std;

vector<bool> IsNto(int(1e7)+1,true);

int rev(int n){
    int ans=0;
    while (n!=0)
    {
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}

void sangnt()
{
    int sz=int(1e7);
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= int(1e6) ; ++i)
    {
        if(IsNto[i]){
            for (int j = i*i; j < int(1e6); j+=i)
            {
                IsNto[j]=false;        
            }
        }

        
    }
    
}

int main()
{
    int a,b;
    cin>>a>>b;
    sangnt();
    int ans=0;
    for (int i = a; i <= b; i++)
    {
        if(IsNto[i]&&IsNto[rev(i)])ans++;
    }
    cout<<ans;
}