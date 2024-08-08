#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,tol=0;
    cin>>n>>q;
    string str;
    vector<pair<int,int>> a;
    vector<int> ans;
    ans.push_back(0);
    cin.ignore();
    getline(cin, str);
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    for(auto i:str){
        if(i != ' '){
            tol+=int(i)-48;
            ans.push_back(tol);
        }
    }
    for(auto i:a){
        cout<<ans[i.second]-ans[i.first-1]<<endl;
    }
}