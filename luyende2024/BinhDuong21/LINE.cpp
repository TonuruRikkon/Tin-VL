#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main()
{
    int m,n,k,tol=0,max1=0,max2=0;
    cin>>m>>n>>k;
    map<int,int> a;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            int x;
            cin>>x;
            a[x]++;
        }
        
    }
    for(auto x:a){
        ans.push_back(x.second);
    }
    sort(ans.begin(),ans.end(),cmp);
    for (int i = 0; i < k; i++)
    {
        tol+=ans[i];
    }
    cout<<tol;
}