#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    inp.push_back(0);
    int n,tol=0,ans=0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        tol+=x;
    }
    for(int x:inp){
        int temp=tol;
        if((tol-x)%2==0) {
            ans=max((tol-x)/2,ans);
        }
    }
    cout<<ans;
}