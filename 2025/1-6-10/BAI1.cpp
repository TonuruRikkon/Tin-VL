#include <bits/stdc++.h>
using namespace std;

vector<bool>isNto(int(1e5)+1,true);
vector<int> Nto;

void sangnt(){
    isNto[0]=isNto[1]=false;
    for (int i = 2; i*i <= int(1e5); i++)
    {
        if(isNto[i]==true){
            Nto.push_back(i);
            for (int j = i*i; j <= int(1e5); j+=i)
            {
                isNto[j]=false;
            }
            
        }
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sangnt();
    int k,a,b;
    cin>>k>>a>>b;
    int ans=0;
    for (int i = a; i <= b; i++)
    {
        int temp=i;
        for(int x:Nto){
            if(x>k) break;
            while (temp%x==0)
            {
                temp/=x;
            }
        }
        if(temp==1) {
            ans++;
        }
    }
    cout<<ans;
}