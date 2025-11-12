#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    

    vector<int> curr(n),prev(n);
    for (int i = n - 1; i >= 0; i--)
    {
        curr[i]=1;
        for (int j = i+1; j < n; j++)
        {
            if(inp[i]==inp[j]){
                curr[j]=prev[j-1]+2;
            }
            else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    cout<<n-curr[n-1];
    
}