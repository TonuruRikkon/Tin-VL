#include <bits/stdc++.h>
using namespace std;

int sld_win(int n,int k,vector<int> inp)
{
    unordered_map<int,int> mp;
    int L=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        mp[inp[i]]++;
        while (mp[inp[i]]>=k)
        {
            mp[inp[i]]--;
            L++;
            ans+=(n-i);
        }   
    }
    return ans;
}

int main()
{
    vector<int> inp;
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    cout<<sld_win(n,k,inp);
}