#include <bits/stdc++.h>
using namespace std;

void fibonaci(vector<long long> &fibo, map<long long,long long> &mpfibo)
{
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 1; ; i++)
    {
        long long sum=fibo[i]+fibo[i-1];
        fibo.push_back(sum);
        mpfibo[sum]=1;
        if(fibo[i+1]>=1e14){
            break;
        }
    }
    
    
}

int main()
{
    int n;
    cin>>n;
    vector<long long> fibo;
    map<long long,long long> asfibo;
    fibonaci(fibo,asfibo);
    vector<long long> inp,tol;
    tol.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        tol.push_back(tol[i]+x);
    }
    int ans=0;
    
    for (int l = 1; l <= n; l++)
    {
        for (int r = n; r > 0; r--)
        {
            long long sum=tol[r]-tol[l-1];
            if(asfibo[sum]!=0){
                ans=max(r-l+1,ans);
                break;
            }
        }
        
    }
    cout<<ans;
}