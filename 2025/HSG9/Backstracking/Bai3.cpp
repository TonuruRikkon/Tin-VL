#include <bits/stdc++.h>
using namespace std;

int tol=0;

void dequy(vector<string>&RC,vector<string>inp,int q,int a)
{
    if(RC.size()==q)
    {
        tol++;
        cout<<tol<<'.';
        for(string x:RC) cout<<' '<<x;
        cout<<'\n';
    }
    for (int i=a; i < inp.size(); i++)
    {
        RC.push_back(inp[i]);
        dequy(RC,inp,q,i+1);
        RC.pop_back();
    }
    
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<string> inp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        inp.push_back(str);
    }
    vector<string> RC;
    dequy(RC,inp,q,0);
}