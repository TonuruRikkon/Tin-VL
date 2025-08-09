#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp;
    int k;
    cin>>inp>>k;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        cin>>x>>y;
        string ref=inp.substr(x-1,y-x+1);
        string inv=ref;
        reverse(inv.begin(),inv.end());
        if(ref==inv) cout<<1<<'\n';
        else cout<<-1<<'\n';
    }
    
}