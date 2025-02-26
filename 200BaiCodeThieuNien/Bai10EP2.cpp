#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n,p,d=0;
        cin>>n>>p;
        for (int j = 1; j <= n; j++)
        {
            int tmp=j;
            while (tmp%p==0)
            {
                tmp/=p;
                d++;
            }
        }
        cout<<d<<"\n";
    }
     
}