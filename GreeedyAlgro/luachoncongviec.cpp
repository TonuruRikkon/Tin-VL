#include<bits/stdc++.h>
using namespace std;

struct luachoncongviec
{
    int st,en;
}a[int(1e6)+1];


int main()
{
    memset(a,0,sizeof(a));
    int n,last=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cin>>a[x].st>>a[x].en;
    }
    vector<pair<int,pair<int,int>>> ans;

    for (int i = 1; i <= n; i++)
    {
        if(a[i].st>=last){
            ans.push_back(make_pair(i,make_pair(a[i].st,a[i].en)));
            last=a[i].en;
        }
    }
    cout<<"--------------------"<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second.first<<"-"<<i.second.second<<endl;
    }
}