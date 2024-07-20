#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
    }
    cout<<*min_element(c.begin(),c.end())<<endl;
    cout<<*max_element(c.begin(),c.end());

}