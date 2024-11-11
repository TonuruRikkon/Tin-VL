#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long tol=0;
    cin>>n;
    map<int,int> a;
    vector<long long> ans;
    for (int i = 0; i < n*n; i++)
    {
        int x;
        cin>>x;
        a[x]+=1;
        tol+=x;
    }
    for(auto x:a){
        ans.push_back(tol-(x.first*x.second));
    }
    cout<<*max_element(ans.begin(),ans.end());
}