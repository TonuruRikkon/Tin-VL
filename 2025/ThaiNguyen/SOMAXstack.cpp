#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    stack<int> stk;
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        if(stk.empty()){
            stk.push(inp[i]);
            ans[i]=-1;
        }
        else{
            while (stk.top()<inp[i])
            {
                stk.pop();
            }
            if(!stk.empty()) ans[i]=stk.top();
            else ans[i]=-1;
            stk.push(inp[i]);
        }
    }   
    for (int x : ans)
    {
        cout<<x<<' ';
    }
    
}