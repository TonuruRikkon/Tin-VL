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
    int prev=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]>prev){
            tol+=a[i]-prev;
            prev=a[i];
        }
        else{
            if(ans<tol) ans=tol;
            tol=0;
            prev=a[i];
        }
    }
    if(ans<tol) ans=tol;
    cout<<ans;

}