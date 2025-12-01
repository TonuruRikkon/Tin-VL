#include <bits/stdc++.h>
using namespace std;

int  main()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    vector<int> inp(n);
    int k=1;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    for (int i = 0; i+k < n; i+=k)
    {
        while(inp[i+k]<k) k++;
    }
    cout<<k;
    
}