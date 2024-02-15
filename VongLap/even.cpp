#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<0) cout<<"LOI";
    else
    {
        for(int i=2; i<=n; i++) 
        {
            if(i%2==0) cout<<i<<" ";
        }
    }
    return 0;
}