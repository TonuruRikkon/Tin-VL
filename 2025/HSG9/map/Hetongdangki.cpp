#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<string,int> inp;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        if(inp[str]==0){
            cout<<"OK"<<'\n';
        }
        else cout<<str+char('0'+inp[str])<<'\n';
        inp[str]++;
    }
    
}