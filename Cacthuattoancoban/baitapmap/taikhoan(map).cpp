#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> acc;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        acc[x]++;
        if(acc[x]==1) cout<<x<<endl;
        else cout<<x<<acc[x]-1<<endl;
    }
    
}