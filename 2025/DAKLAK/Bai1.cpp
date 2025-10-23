#include <bits/stdc++.h>
using namespace std;

long long sum(long long n){
    return (n*(n+1)*(2*n+1))/6;
}

int main()
{
    long long n;
    cin>>n;
    long long l=0,r=n;
    long long tol=0,mid=l+(r-l)/2;
    while (l<r)
    {
        tol=sum(mid);
        if(tol<n){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        mid=l+(r-l)/2;
    }
    
    cout<<mid<<'\n'<<n-sum(mid);
}