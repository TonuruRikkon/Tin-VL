#include <bits/stdc++.h>
using namespace std;

vector<bool> IsNto(INT_MAX,true);
vector<int> Nto;

void sangnt()
{
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= int(1e5); i++)
    {
        if(IsNto[i]==true){
            Nto.push_back(i);
            for (int j = i*i; j <= int(1e5); j+=i)
            {
                IsNto[j]=false;
            }
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    sangnt();
    bool check=false;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        int ref=0;
        for(int y:Nto){
            if(x%y==0){
                ref+=y;
            }
            if(y>x) break;
        }    
        if(ref%5==0) {
            cout<<x<<' ';
            check=true;
        }
    }
    if(check==false) cout<<-1;
}