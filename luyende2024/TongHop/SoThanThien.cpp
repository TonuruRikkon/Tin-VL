#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    for (int i = a; i <= b; i++)
    {
        string str=to_string(i);
        reverse(str.begin(),str.end());
        int n=atoi(str.c_str());
        if(__gcd(i,n)==1) ans++;
    }
    cout<<ans;
}