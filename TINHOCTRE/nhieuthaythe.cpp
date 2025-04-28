#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,vector<int>> tol;
    for (int i = 0; i < n; i++)
    {
        tol[s[i]].push_back(i);
    }
    int q;
    cin>>q;
    for (long long o = 0; o < q; o++)
    {
        char x,y;
        cin>>x>>y;
        for(char j:tol[x]){
            tol[y].push_back(j);
        }
        tol.erase(x);
    }
    vector<char>ans(n);
    for(auto x:tol){
        for(int y:x.second){
            ans[y]=x.first;
        }
    }
    string answer="";
    for (int i = 0; i < n; i++)
    {
        answer+=ans[i];
    }
    cout<<answer<<'\n';
}