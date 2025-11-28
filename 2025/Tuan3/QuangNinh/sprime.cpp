#include <bits/stdc++.h>
using namespace std;

int MAXN=3*int(1e6);

vector<bool> IsNto(MAXN+1,true);
vector<int> Nto5(MAXN+1,0);

int charsum(int n){
    int ans=0;
    while (n!=0)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}

void sangnt(){
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <=MAXN; i++)
    {
        if(IsNto[i]){
            for (int j = i*i; j <= MAXN; j+=i)
            {
                IsNto[j]=false;
            }
            
        }
    }
    for (int i = 1; i <= MAXN; i++)
    {
        Nto5[i]=Nto5[i-1];
        if(IsNto[i]){
            if(charsum(i)%5==0) Nto5[i]++;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    sangnt();
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<Nto5[r]-Nto5[l-1]<<'\n';
    }
    
}