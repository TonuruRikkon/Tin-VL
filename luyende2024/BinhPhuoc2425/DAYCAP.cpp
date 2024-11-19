#include <bits/stdc++.h>
using namespace std;

long long k;

bool cancat(int n,vector<int> inp){
    long long ans=0;
    for(int x:inp){
        ans+=x/n;
    }
    return ans>=k;
}

long long binarysrch(long long R,long long L,vector<int> inp){
    long long mid,ans=0;
    while (L<=R)
    {
        mid=(L+R)/2;
        if(cancat(mid,inp)==true){
            ans=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    return mid;
}

int main()
{
    int n,r=0;
    cin>>n>>k;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
        r=max(r,x);
    }
    cout<<binarysrch(r,1,inp);
}