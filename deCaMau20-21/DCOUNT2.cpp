#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    map<long long,int> isodd; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        isodd[x]++;
        if(isodd[x]%2!=0){
            ans++;
        }
        else{
            ans--;
        }
    }
    cout<<ans;
}