#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,dem=0,tong=0;
    cin>>n;
    while (n!=0)
    {
        tong = tong+n%10;
        n =n / 10;
        dem++;
    }
    cout<<dem<<" "<<tong<<endl;
    return 0;
    
}