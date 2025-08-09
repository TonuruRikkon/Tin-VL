#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> inp;
    int tol=n*(n-1)/2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp[x]++;
    }
    for (auto x:inp)
    {
        tol-=(inp[x.first]-1);
    }
    cout<<tol-inp.size()+2;
}
