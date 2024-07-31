#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> e;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        e[x]++;
        if(e[x]==1) cout<<"OK"<<endl;
        else cout<<x<<e[x]-1<<endl;
    }
    
}