#include <bits/stdc++.h>
using namespace std;

int mid(vector<long long> a, int i, int k)
{
    int L=0,R=i-1,kq=-1,M;
    while (L<=R)
    {
        M=(L+R)/2;
        if(a[i]-a[M]>=k){
            kq=M;
            L=M+1;
        }
        else{
            R=M-1;
        }
    }
    return kq;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    vector<int> ans(n,0);
    for (int i = 0; i < n; i++)
    {
        int j=mid(a,i,k);
        if(j!=-1){
            ans[i]=max(ans[i],b[i]+ans[j]);
        }
        else{
            ans[i]=max(ans[i],b[i]);
        }
    }
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    cout<<*max_element(ans.begin(),ans.end());
}