#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin>>n;
        int ans=0;
        map<int,int> as;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            as[x%5]++;
        }
        for(auto y:as){
            if(y.first==0){
                ans+=y.second;
                y.second=0;
            }
            ans+=min(as[y.first%5],as[5-y.first%5]);
            if(as[y.first%5]>as[5-y.first%5]){
                as[y.first%5]-=as[5-y.first%5];
                as[5-y.first%5]=0;
            }
            else{
                as[5-y.first%5]-=as[y.first%5];
                as[y.first%5]=0;
            }
        }
        cout<<ans;
        if(i!=q-1) cout<<'\n';
    }
    
}