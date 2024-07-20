#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> c;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        c.push_back(x);
    }
    int a;
    cin>>a;
    auto it = lower_bound(c.begin(), c.end(),a);
    cout<<distance(c.begin(),it);
}