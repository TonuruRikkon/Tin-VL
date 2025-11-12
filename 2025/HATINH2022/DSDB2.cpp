#include <bits/stdc++.h>
using namespace std;

int n;


int LPS(vector<int>inp){

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
    
    return curr[n-1];
}

int main(){
    freopen("DSDB.INP","r",stdin);
    freopen("DSDB.OUT","w",stdout);
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    
    cout<<n-LPS(inp);
}