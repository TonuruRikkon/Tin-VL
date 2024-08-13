#include <bits/stdc++.h>
using namespace std;

struct hanghoa
{
    int sl;
    int long long gia;
    string ma;
}a[1000];


int main()
{
    int n,tol=0;
    string check;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].ma>>a[i].sl>>a[i].gia;
    }
    cin>>check;
    for(int i=0; i<n;i++){
        if(a[i].ma==check) tol+=a[i].sl*a[i].gia;
    }
    cout<<tol;
}