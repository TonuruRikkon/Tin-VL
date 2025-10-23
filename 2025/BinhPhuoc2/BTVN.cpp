#include <bits/stdc++.h>
using namespace std;

void sangnt(vector<int> &listnt, vector<bool> &nto)
{
    nto[0]=nto[1]=false;
    for (long long i = 2; i*i < int(1e7); i++)
    {
        if(nto[i]==false) continue;
        listnt.push_back(i);
        for (long long j = i*i; j < int(1e7); j+=i)
        {
            nto[j]=false;
        }
        
    }
    
}

long long mugiaithua(long long n, long long j)
{
    long long tol=0,poww=j;
    for (long long i = 1; i < n; i++)
    {
        if(poww>n) break;
        tol+=n/poww;
        poww*=j;
    }
    return tol;
}

int main()
{
    int t;
    cin>>t;
    vector<int> ntlist;
    vector<bool> nto(int(1e7),true);
    sangnt(ntlist,nto);
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        auto pos=upper_bound(ntlist.begin(),ntlist.end(),n);
        long long acc=1;
        for (int j = 0; j < pos-ntlist.begin(); j++)
        {
            long long tol=0;
            long long a=mugiaithua(n,ntlist[j]);
            for (int k = 0; k <= a; k++)
            {
                int poww=1;
                for (int l = 0; l < k; l++)
                {
                    poww*=ntlist[j];
                }
                tol+=poww;
            }
            acc*=tol;
        }
        cout<<acc<<'\n';
    }
    

}
