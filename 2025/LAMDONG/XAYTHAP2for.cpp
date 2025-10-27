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
    vector<int> ans(n,1);
    for (int i = 0; i < n; i++)
    {
        bool check=inp[i]>0;
        int last=abs(inp[i]);
        for (int j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(check!=inp[j]>0){
                if(last>abs(inp[j])){
                    ans[i]++;
                    check=inp[j]>0;
                    last=abs(inp[j]);
                }
            }
        }
        
    }
    cout<<*max_element(ans.begin(),ans.end());
}