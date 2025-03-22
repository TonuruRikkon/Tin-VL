#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp,tempvc,outp,org;
    int n,split=-1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    for(int i=n-1; i>0;i--){
        if(inp[i]>=inp[i-1]){
                split=n-i;
        }
        else break;
    }
    if(split!=inp.size()-1) rotate(inp.begin(), inp.begin()+split,inp.end());
    int lastchecked=0,d=1;
    cout<<split<<"\n";
    for (int i = 1; i < n; i++)
    {
        if(inp[lastchecked]<inp[i]){
            d++;
            lastchecked=i;
        }
    }
    cout<<d;
}