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
        else inp[x]++;
    }
    for(auto x:inp){
        if(x.second!=0){
        int temp=3-(x.first%3);
        ans+=x.second*inp[abs(x.first-temp)];
        inp[x.first]=0;
        inp[abs(x.first-temp)]=0;
        }
    }
    cout<<ans;
}