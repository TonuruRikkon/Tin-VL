#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,tol=0,a[1000];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if(a[i]>a[i-1]){
            tol+=a[i]-a[i-1];
        }
        else{
            if(ans<tol) ans=tol;
            tol=0;
        }
    }
    if(ans<tol) ans=tol;
    cout<<ans;

}