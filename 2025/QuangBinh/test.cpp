#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        m.push_back(x);
    }
    sort(m.begin(),m.end(),greater());
    for (int i = 0; i < n; i++)
    {
        cout<<m[i]<<' ';
    }
    
}