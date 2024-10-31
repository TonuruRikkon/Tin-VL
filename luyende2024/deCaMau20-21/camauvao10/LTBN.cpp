#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,prev=0,temp=1,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(prev==x) temp++;
        else{
            ans=max(ans,temp);
            temp=1;
            prev=x;
        }
    }
    cout<<ans;
}