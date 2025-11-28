#include <bits/stdc++.h>
using namespace std;

vector<bool> IsNto(int(1e6)+1,true);
vector<int> NtoDep(int(1e6)+1);

bool check(int n){
    while (n!=0)
    {
        if(n%10==3||n%10==5||n%10==7) return false;
        else{
            n/=10;
        }
    }
    return true;
}

void sangnt(){
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= int(1e6); i++)
    {
        if(IsNto[i]){

            for (int j = i*i; j <= int(1e6); j+=i)
            {
                IsNto[j]=false;
            }
            
        }
    }
    NtoDep[0]=0;
    for (int i = 1; i <= int(1e6); i++)
    {
        NtoDep[i]=NtoDep[i-1];
        if(IsNto[i]){
            if(check(i)) ++NtoDep[i];
        }
    }
    
}


int main()
{
    int n;
    cin>>n;
    sangnt();
    cout<<NtoDep[n];
}