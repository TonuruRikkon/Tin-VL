#include <bits/stdc++.h>
using namespace std;
int dem(int n)
{
    int dem=0;
    while(n!=0)
    {
        dem++;
        n=n/10;
    }
    return dem;
}
int daoso(int n)
{
    int s=0;
    while(n!=0){
        s=(s*10)+n%10;
        n=n/10;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    if(daoso(n)==n) cout<<"YES";
    else cout<<"NO";
}