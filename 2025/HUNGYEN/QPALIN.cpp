#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int n,q;
    cin>>n>>q;
    cin>>str;
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        string temp=str.substr(x-1,y-x+1);
        string rev=temp;
        reverse(rev.begin(),rev.end());
        if(temp==rev) cout<<1;
        else cout<<0;
        if(i!=q-1) cout<<'\n';
    }
    
}