#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> c;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
    }
    reverse(c.begin(),c.end());
    for (int i = 0; i < n; i++)
    {
        cout<<c[i]<<" ";
    }
    
}