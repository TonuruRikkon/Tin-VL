#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long L,R;
    cin>>L>>R;
    unsigned long long tL=L,tR=R;
    if(L%2!=0) tL=L+1;
    if(R%2!=0) tR=R-1;
    if(L>0){
        long long ans=0;
        for(int i=tL;i<=R;i+=2){
        }
        cout<<ans;
    }
}