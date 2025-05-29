#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        inp.emplace_back(a);
    }
    int min=inp[0],d=0;
    map<int,int> ans;
    for (int i = 0; i < n; i++)
    {
        if(inp[i]>=min){
            d++;
        }
        else{
            ans[min]=d;
            d=1;
            min=inp[i];
        }
    }
    ans[min]=d;
    unsigned long long out=0;
    for(auto x:ans){
        out+=x.first*x.second;
    }
    cout<<out*3;
}