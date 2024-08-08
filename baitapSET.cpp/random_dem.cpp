#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,tol=0,ans=0;
    cin>>k;
    set<int> a;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        a.insert(x);
    }
    cout<<a.size();
}