#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,is_3=0;
    cin>>n;
    map<int,int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(x%3==0) is_3++;
        else inp[x%3]++;
    }
    ans+=(is_3*(is_3-1))/2+(inp[2]*inp[1]);
    cout<<ans;
}