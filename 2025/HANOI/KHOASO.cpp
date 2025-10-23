#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0,mk[4]={2,0,2,5};
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin>>x;
        ans+=min(abs(x-mk[i]),(10-x+mk[i]));
    }
    cout<<ans;
}