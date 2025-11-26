#include <bits/stdc++.h>
using namespace std;

vector<bool> IsNto(int(1e5)+1,true);
void sangnt()
{
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= int(1e5); i++)
    {
        if(IsNto[i]==true){
            for (int j = i*i; j <= int(1e5); j+=i)
            {
                IsNto[j]=false;
            }
            
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    vector<int> inp;
    int x;
    while (cin>>x)
    {
        inp.push_back(x);
    }
    sangnt();
    for (int i = inp.size()-2; i >= 0 ; i--)
    {
        if(IsNto[inp[i+1]]&&IsNto[inp[i-1]]) {
            cout<<i+1;
            break;
        }
    }
    
    
}