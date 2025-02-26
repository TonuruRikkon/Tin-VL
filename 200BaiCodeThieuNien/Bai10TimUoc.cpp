#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n,p,tmp=0;
        cin>>n>>p;
        while (n/p>0)
        {
            tmp+=n/p;
            n/=p;
        }
        cout<<tmp<<"\n";
    }
    
}