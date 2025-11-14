#include <bits/stdc++.h>
using namespace std;

vector<bool> isNto(INT_MAX,true);
vector<int> Nto;
vector<int> tolNto;

void sangnt(){
    isNto[0]=isNto[1]=false;
    for (int i = 2; i*i <= int(1e7); i++)
    {
        if(isNto[i]==true){
            Nto.push_back(i);
            for (int j = i*i; j <= int(1e7); j+=i)
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
    freopen("COUNTPRIME.INP","r",stdin);
    freopen("COUNTPRIME.OUT","w",stdout);
    sangnt();
    int sz=Nto.size();
    tolNto.push_back(0);
    for (int i = 0; i < sz; i++)
    {
        tolNto.push_back(tolNto[i]+Nto[i]);
    }
    
    int n;
    int d=0;
    while (cin>>n)
    {
        if(d!=0)cout<<'\n';
        d++;
        if(n==1){
            cout<<1;
            continue;
        }
        auto temp=lower_bound(tolNto.begin(),tolNto.end(),n);
        if(*temp==n) cout<<temp-tolNto.begin();
        else if(isNto[*temp-n]==true){
            cout<<temp-tolNto.begin()+1;
        }
        else if(isNto[n]==true){
            cout<<1;
        }
        else cout<<0;
    }
    

}