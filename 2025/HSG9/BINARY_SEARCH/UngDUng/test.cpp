#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp={1,3,9,10};
    auto it = lower_bound(inp.begin(),inp.end(),4);
    *it=90;
    for(int x:inp){
        cout<<x<<' ';
    }
}