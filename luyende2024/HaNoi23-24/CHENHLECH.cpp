#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,maxx=0,minn=int(1e9);
    cin>>n;
    map<char,int> a;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin>>x;
        a[x]++;
    }
    for(auto x:a){
        if(x.second>maxx) maxx=x.second;
        if(x.second<minn) minn=x.second;
    }
    cout<<maxx-minn;
}