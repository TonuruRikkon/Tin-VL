#include <bits/stdc++.h>
using namespace std;

int bs(int n, long long x, long long tol)
{
    int l=0,r=tol;
    long long ans=0;
    while(l<r){
        int pos=l+(r-l)/2;
        if(pos*x> tol){
            r--;
        }
        else{
            if(ans<pos)ans=pos;
            l++;
        }
    }
    return ans;
}

int main()
{
    int n,k;
    long long tol=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        tol+=x;
    }
    cout<<bs(n,k,tol);
}