#include <bits/stdc++.h>
using namespace std;

int main()
{
    int_fast64_t dem=0;
    int long long n,x;
    vector<int long long>a;
    cin>>n>>x;
    for (int i = 0; i < n; i++)
    {
        int long long x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[i]+a[j]==x)dem++;
        }
    }
    cout<<dem;
}