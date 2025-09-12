#include <bits/stdc++.h>
using namespace std;

bool ok(map<char,int> tol, map<char,int> ref)
{
    for(auto x:tol){
        if(x.first=='*') continue;
        else if(x.second>ref[x.first]) return false;
        else if(x.second<ref[x.first]&&x.second+tol['*']<x.second) 
        {
            return false;
        }
        else if(x.second+tol['*']>=ref[x.first]){
            tol[x.first]-=ref[x.first]-tol[x.first];
        }
    } 
    return true;
}

int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    string t,s;
    cin>>t>>s;
    map<char,int> ref,tol;
    vector<char> temp;
    for (int i = 0; i < n; i++)
    {
        ref[t[i]]++;
    }
    
    for (int i = 0; i < m; i++)
    {
        if(temp.size()!=n){
            temp.push_back(s[i]);
            tol[s[i]]++;
            if(temp.size()!=n) continue;
        }

        bool check=ok(tol,ref);
        

        if(check==true){
            ans++;
        }
        tol[temp[0]]--;
        temp.erase(temp.begin());
    }

    cout<<ans;

}
