#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        int n;
        cin>>n;
        int zeros=0;
        int tol=0;
        for(int i=0; i<n;i++){
            int x;
            cin>>x;
            tol+=x;
            if(x==0){
                zeros++;
            }
        }
        int ans=0;
        if(zeros==0){
            if(tol==0) ans++;
        }
        else{
            ans+=zeros;
        }
        cout<<ans<<'\n';
    }
}
