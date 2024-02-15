#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,n,lt=1;
    cin>>x>>n;
    while (n!=0)
    {
        lt =lt*x;
        n--;
    }
    cout<<lt<<endl;
}