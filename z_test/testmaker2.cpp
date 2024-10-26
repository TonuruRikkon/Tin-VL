#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("outfile/cstring.inp", "w",stdout);
    int n;
    string a,b="";
    cin>>a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        b+=a;
        for (int j = 0; j < i; j++)
        {
            b+="abygad";
        }
        
    }
    cout<<b;
    
}