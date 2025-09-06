#include <bits/stdc++.h> 
using namespace std;

int main()
{
    map<int,int> inp;
    int n,k,ans=0;
    cin>>n>>k;
    for (int  i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp[x]++;
    }
    for (int i = 1; i <= ceil(float(k)/2); i++)
    {
        if(k-i==i){
            ans+=inp[i]*(inp[i]-1)/2;
        }
        else{
            ans+=inp[i]*inp[k-i];
        }
    }
    cout<<ans;
    
}