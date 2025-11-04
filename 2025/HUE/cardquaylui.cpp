#include <bits/stdc++.h>
using namespace std;

int demvadoi(vector<int> inp, vector<int> inp2, int n, int m, int x)
{
    inp[x]=inp2[x];
    int ans=x;
    m--;
    for (int i = x+1; i < n; i++)
    {
        if(inp[i]!=inp[i-1]){
            if(m==0) break;
            ans=demvadoi(inp,inp2,n,m,i);
        }
        else ans++;
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inp,inp2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp2.push_back(x)
    }
    

    
    
}