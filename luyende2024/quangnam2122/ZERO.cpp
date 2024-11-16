#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,tol=0;
    cin>>n;
    map<int,int> thongke;
    thongke[0]=0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        tol+=x;
        if(thongke.find(tol)==thongke.end()){
            thongke[tol]=i;
        }
        else if(thongke.find(tol)!=thongke.end()){
            ans=max(ans,i-thongke[tol]);
        }
    }
    cout<<ans;
    
}