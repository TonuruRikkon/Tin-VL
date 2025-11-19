#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("TROCHOI.INP", "r", stdin);
    // freopen("TROCHOI.OUT", "w", stdout);
    int m,n;
    cin>>m>>n;
    int mul=n*m;
    vector<int> inp(mul);
    for (int i = 0; i < mul; i++)
    {
        cin>>inp[i];
    }
    sort(inp.begin(),inp.end());
    int temp=0;
    for (int i = 0; i < m; i++)
    {
        if(i!=0) cout<<'\n';
        if(i%2==0){
            for (int j = 0; j < n; j++)
            {
                cout<<inp[temp+j]<<' ';
            }
            
        }
        else{
            for (int j = n - 1; j >= 0; j--)
            {
                cout<<inp[temp+j]<<' ';
            }
        }
        temp+=n;
    }
    
    
}