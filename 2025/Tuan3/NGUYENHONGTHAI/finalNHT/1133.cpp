#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,n;
    cin>>s>>n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    sort(inp.begin(),inp.end(),greater<int>());
    bool check=false;
    int ans=0,tol=0;
    for(int x:inp){
        tol+=x;
        ans++;
        if(tol>=s){
            check=true;
            break;
        }
    }
    if(check==false) cout<<"impossible";
    else cout<<ans;

}