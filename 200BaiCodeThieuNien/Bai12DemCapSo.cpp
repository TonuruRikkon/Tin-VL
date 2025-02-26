#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin>>k;
        int dem=0;
        for (int i = 1; i < k/2; i++)
        {
            dem+=k-i-1;
        }
        cout<<dem<<"\n";
    }
    
}