#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tol=0,ans=0;
    cin>>n;
    map<int,int> tong;
    tong[0]=0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        tol+=x;
        cout<<tol<<" ";
        for(auto x:tong){
            if(tol-x.first<0){
                ans=max(ans,i-x.second);
                break;
            }
        }
        tong[tol]=i;
    }
    cout<<endl;
    cout<<ans;
}