#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp,fst,fed;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    int d=0,lastchecked=-1;
    for (int i = 1; i < n; i++)
    {
        if(lastchecked<inp[i]){
            d++;
            lastchecked=inp[i];
        }
        fst.emplace_back(d);
    }
    int d2=INT_MAX,lastchecked2=-1;
    for (int i = n-1; i >= 0; i--)
    {
        if(lastchecked2>inp[i]){
            d++;
            lastchecked2=inp[i];
        }
    }
    
}