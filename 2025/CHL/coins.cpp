#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp(int(1e6)+1,0);
    inp[0]=1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp[x]=1;
    }
    for (int i = 1; i <= int(1e6); i++)
    {
        if(inp[i]==0){
            cout<<i;
            break;
        }
    }
    
}