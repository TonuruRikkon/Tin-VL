#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int sz=str.size();
    vector<int> tol(sz+1);
    tol[0]=0;
    unordered_map<int,int> pos;
    int ans=0;
    for (int i = 1; i <= sz; i++)
    {
        tol[i]=tol[i-1];
        if(str[i-1]=='V') tol[i]++;
        else tol[i]-=2;
        if(pos[tol[i]]==0&&tol[i]!=0) pos[tol[i]]=i;
        if(pos[tol[i]]!=0||tol[i]==0) ans=max(ans,i-pos[tol[i]]);
    }
    cout<<ans;
}