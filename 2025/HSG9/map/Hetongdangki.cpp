#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
        else {
            cout<<str<<inp[str]<<'\n';
        }
        inp[str]++;
    }
    
}