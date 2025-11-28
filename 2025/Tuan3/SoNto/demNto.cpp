#include <bits/stdc++.h>
using namespace std;

vector<bool> IsNto(int(1e6)+1,true);
vector<int> DemNto(int(1e6)+1,0);

void sangnt(){
    int MAXn=int(1e6);
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= MAXn; i++)
    {
        if(IsNto[i]){
            for (int j = i*i; j <= MAXn; j+=i)
            {
                IsNto[j]=false;
            }
            
        }
    }
    for (int i = 1; i <= int(1e6); i++)
    {
        DemNto[i]=DemNto[i-1];
        if(IsNto[i]) DemNto[i]++;
    }
    
}

int main()
{
    int t;
    cin>>t;
    sangnt();

    for (int i = 0; i < t; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<DemNto[r]-DemNto[l-1]<<'\n';
    }
    
}