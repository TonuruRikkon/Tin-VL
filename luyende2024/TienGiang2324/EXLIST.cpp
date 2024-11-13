#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("EXLIST.INP", "r", stdin);
    freopen("EXLIST.OUT", "w", stdout);
    int n,tol=0,length=0;
    vector<int> inp;
    cin>> n;
    vector<int> Vtol(n+1);
    map<int,int> start;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        Vtol[i+1]=Vtol[i]+x;
    }
    for(int i=0;i<n;i++){
        if(start.find(inp[i])==start.end()) start[inp[i]]=i;
        else{
            if(i-start[inp[i]]+1>length){
                    tol=Vtol[i+1]-Vtol[start[inp[i]]];
                    length=i-start[inp[i]]+1;
            }
            else if(i-start[inp[i]]+1==length){
                if(Vtol[i+1]-Vtol[start[inp[i]]]>tol){
                    tol=Vtol[i+1]-Vtol[start[inp[i]]];
                }
            }
        }
    }
    cout<<length<<" "<<tol;
}