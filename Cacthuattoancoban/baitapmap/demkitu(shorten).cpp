#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,maxx=0;
    cin>>n>>k;
    string str;
    cin>>str;
    map<char,int> d;
    for (int i = 0; i < n; i++)
    {
        d[str[i]]++;
        if(maxx<d[str[i]]) {
            maxx=d[str[i]];
        }
    }
    for(auto i:d){
        if(i.second==maxx) cout<<i.first<<" "<<maxx<<endl;
    }
}