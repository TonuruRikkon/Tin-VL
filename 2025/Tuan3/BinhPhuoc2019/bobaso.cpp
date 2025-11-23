#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    vector<int> Ai(n+1,0);
    vector<int> Ak(n+1,0);
    for (int i = 1; i <= n-2; i++)
    {
        Ai[i]=max(Ai[i-1],inp[i-1]);
    }
    for (int i = 1; i <= n-2; i++)
    {
        Ak[i]=max(Ak[i-1],inp[n-i]*3);
    }
    int ans=0;
    for (int i = 1; i < n-1; i++)
    {
        ans=max(ans,(Ai[i]+2*inp[i]+Ak[n-(i+2)]));
    }
    cout<<ans;
    
}