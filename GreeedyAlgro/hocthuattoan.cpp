#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,n,ans=0,d=0;
    cin>>x>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    for (int i = a[0]; i <= x; i+=a[d])
    {
        d++;
    }
    cout<<d;
}