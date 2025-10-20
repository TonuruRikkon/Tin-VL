#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,last=INT_MIN,ans=0,temp=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(x>last){
            temp++;
        }
        else{
            ans=max(ans,temp);
            temp=1;
        }
        last=x;
    }
    cout<<ans;
}