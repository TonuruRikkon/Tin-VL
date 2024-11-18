#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<a.back();
}