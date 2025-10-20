#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,maxx=INT_MIN;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(x<=k){
            maxx=max(maxx,x);
        }
    }
    cout<<maxx;
}