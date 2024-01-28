#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    if(abs(a-b)<c&&c<(a+b)) cout<<"YES";
    else cout<<"NO";
    return 0;
}
