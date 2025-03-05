#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x;
    cin>>x;
    if(x-0.5<=int(x))
    cout<<int(x);
    else cout<<int(x+1);
}