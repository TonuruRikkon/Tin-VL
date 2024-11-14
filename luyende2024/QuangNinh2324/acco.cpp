#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("acco.inp","r",stdin);
    freopen("acco.out","w",stdout);
    int n;
    map<string,int> acc;
    vector<string> ans;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        acc[x]++;
        if(acc[x]==1) ans.push_back(x);
        else if(acc[x]>1) ans.push_back(x+to_string(acc[x]-1));
    }
    for(string x:ans){
        cout<<x<<endl;
    }
}