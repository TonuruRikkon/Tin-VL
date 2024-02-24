#include <bits/stdc++.h>
using namespace std;
int daoso(int n)
{
    int x,s=0;
    while(n!=0)
    {
        x=n%10;
        s=(s*10)+x;
        n=n/10;
    }
    return s;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<max(daoso(a),daoso(b));
}
