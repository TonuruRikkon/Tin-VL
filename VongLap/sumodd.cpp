#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n;
    s == 0;
    if(n<0) cout<<"loi";
    else
    {
        for(n;n>=0;n--)
        {
            if(n%2!=0) s=s+n;
        }
        cout<<s;
    }
    return 0;
}