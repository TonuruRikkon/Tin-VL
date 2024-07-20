#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s=0;
    cin>>n;
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
        s+=x;
    }
    cout<<s;
}