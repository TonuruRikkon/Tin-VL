#include <bits/stdc++.h>
using namespace std;

long long tong_k(vector<int> inp, int k)
{
    vector<int> cnt;
    for(int x:inp){
        cnt.push_back(x);
    }
    sort(cnt.begin(),cnt.end(),greater());
    int tol=0;
    for (int i = 0; i < k; i++)
    {
        tol+=cnt[i];
    }
    return tol;
}

long long dem(vector<int> inp, int n,int k, int m)
{
    vector<int> cnt(10,0);
    int l=0;
    int ans=0;
    for(int r=0;r<n;r++){
        cnt[inp[r]]++;
        while (true)
        {
            int siz=r-l+1;
            int tol_qlfed=tong_k(cnt,k);
            if(siz-tol_qlfed<=m){
                break;
            }
            
            cnt[inp[l]]--;
            l++;

        }
        ans=max(ans,r-l+1);
    }
    return ans;
}


int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }

    cout<<dem(inp,n,k,m);

    
}