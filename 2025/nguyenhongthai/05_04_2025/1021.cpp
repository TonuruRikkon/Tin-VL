#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans;
    double ref=INT_MAX;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        if(a/(c-b)<ref){
            ref=a/(c-b);
            ans=i;
        }
    }
    cout<<ans;
}