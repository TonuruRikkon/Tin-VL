#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp,tol;
    int n,k;
    long long t=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        t+=x;
        inp.emplace_back(x);
        tol.emplace_back(t);
    }
    
}