#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    map<int,int> pos;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        pos[x]=i;
    }
    vector<int> ans(n,0);
    ans[n-1]=-1;
    vector<int> as(n,0);
    as[n-1]=-1;
    for (int i = n-1 - 1; i >= 0; i--)
    {
        int curr=inp[i+1];
        if(inp[i]<curr){
            ans[i]=curr;
        }
        else{
            while (inp[i]>=curr&&curr!=-1)
            {
                curr=ans[pos[curr]];
            }
            ans[i]=curr;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<' ';
    }
    
    
}