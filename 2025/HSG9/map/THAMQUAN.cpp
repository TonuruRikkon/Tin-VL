#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    map<int,int>cnt;
    int n,k,diff=0,maxx=0,pos=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        cnt[inp[i]]++;
        if(cnt[inp[i]]==1) diff++;
        maxx=diff;
    }
    for (int i = k; i < n-1; i++)
    {
        cnt[inp[i+1]]++;
        cnt[inp[i-k]]--;
        if(cnt[inp[i-k]]==0) diff--;
        if(cnt[inp[i-k]]==1) diff++;
        if(maxx<diff){
            maxx=diff;
            pos=i-k+1;
        }
    }
    cout<<pos;
}