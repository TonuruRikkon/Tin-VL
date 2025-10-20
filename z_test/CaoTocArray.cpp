#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int inp[n],tol[n+1],s[n];
    tol[0]=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp[i]=s[i]=x;
    }
    sort(s,s+n);
    for (int i = 0; i < n; i++)
    {
        tol[i+1]=(tol[i]+s[i]);
    }
    map<int,int> ans;
    for (int i = 1; i <= n; i++)
    {
        int pos=i-1;
        int sumR=s[pos]*(i-1)-tol[i-1];
        int sumL=tol[n]-tol[i-1]-s[pos]*(n-i+1);
        ans[s[pos]]=sumR+sumL;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[inp[i]]<<' ';
    }
    
}